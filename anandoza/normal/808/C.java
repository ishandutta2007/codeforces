import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CTeaParty solver = new CTeaParty();
        solver.solve(1, in, out);
        out.close();
    }

    static class CTeaParty {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int w = in.nextInt();
            int[] a = in.readIntArray(n);

            int[] answer = new int[n];
            for (int i = 0; i < n; i++) {
                answer[i] = (a[i] + 1) / 2;
                w -= answer[i];
            }
            if (w < 0) {
                out.println(-1);
                return;
            }

            int remaining = 0;
            for (int i = 0; i < n; i++) {
                remaining += a[i] / 2;
            }
            if (remaining < w) {
                out.println(-1);
                return;
            }

            while (true) {
                for (int i = 0; i < n; i++) {
                    if (w == 0) {
                        out.println(Util.join(answer));
                        return;
                    }
                    if (a[i] % 2 == 1)
                        continue;
                    if (a[i] - answer[i] == 0)
                        continue;
                    answer[i]++;
                    w--;
                }
                for (int i = 0; i < n; i++) {
                    if (w == 0) {
                        out.println(Util.join(answer));
                        return;
                    }
                    if (a[i] % 2 == 0)
                        continue;
                    if (a[i] - answer[i] == 0)
                        continue;
                    answer[i]++;
                    w--;
                }
            }
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
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
}