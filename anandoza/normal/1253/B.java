import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
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
        BSillyMistake solver = new BSillyMistake();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSillyMistake {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            HashSet<Integer> cur = new HashSet<>();
            HashSet<Integer> left = new HashSet<>();
            List<Integer> indices = new ArrayList<>();
            indices.add(-1);
            for (int i = 0; i < n; i++) {
                int x = a[i];
                if (x > 0) {
                    if (cur.contains(x) || left.contains(x)) {
                        out.println(-1);
                        return;
                    }
                    cur.add(x);
                } else {
                    x *= -1;
                    if (!cur.contains(x)) {
                        out.println(-1);
                        return;
                    }
                    cur.remove(x);
                    left.add(x);
                }
                if (cur.isEmpty()) {
                    indices.add(i);
                    left.clear();
                }
            }
            if (!cur.isEmpty()) {
                out.println(-1);
                return;
            }

            List<Integer> answer = new ArrayList<>();
            for (int i = 0; i + 1 < indices.size(); i++) {
                answer.add(indices.get(i + 1) - indices.get(i));
            }

            out.println(answer.size());
            out.println(Util.join(answer));
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
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
}