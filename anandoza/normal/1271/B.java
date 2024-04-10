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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BBlocks solver = new BBlocks();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBlocks {
        int[] b;
        List<Integer> answer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            b = new int[n];
            char[] input = in.next().toCharArray();
            for (int i = 0; i < n; i++) {
                b[i] = input[i] == 'B' ? 1 : 0;
            }
            int sum = 0;
            for (int x : b)
                sum += x;
            if (sum % 2 == 1 && n % 2 == 0) {
                out.println(-1);
                return;
            }

            answer = new ArrayList<>();

            int target;
            if (sum % 2 == 0) {
                target = 0;
            } else {
                target = 1;
            }

            for (int i = 0; i + 1 < n; i++) {
                if (b[i] != target)
                    op(i);
            }

            out.println(answer.size());
            out.println(Util.join(answer));
        }

        private void op(int i) {
            b[i] ^= 1;
            b[i + 1] ^= 1;
            answer.add(i + 1);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}