import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BKuroniAndSimpleStrings solver = new BKuroniAndSimpleStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class BKuroniAndSimpleStrings {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] input = in.next().toCharArray();
            final int n = input.length;
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = input[i] - '(';
            }

            List<List<Integer>> answer = new ArrayList<>();
            while (true) {
                boolean did = false;
                List<Integer> left = new ArrayList<>();
                List<Integer> rightRev = new ArrayList<>();
                for (int i = 0, j = n - 1; i < j; i++, j--) {
                    while (i < n && s[i] != 0)
                        i++;
                    while (j >= 0 && s[j] != 1)
                        j--;
                    if (i >= j || s[i] != 0 || s[j] != 1)
                        break;
                    left.add(i + 1);
                    rightRev.add(j + 1);
                    s[i] = -1;
                    s[j] = -1;
                    did = true;
                }
                if (!did)
                    break;
                List<Integer> all = new ArrayList<>();
                all.addAll(left);
                for (int j = rightRev.size() - 1; j >= 0; j--)
                    all.add(rightRev.get(j));
                answer.add(all);
            }
            out.println(answer.size());
            for (List<Integer> l : answer) {
                out.println(l.size());
                out.println(Util.join(l));
            }
        }

    }

    static class Util {
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        private Util() {
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}