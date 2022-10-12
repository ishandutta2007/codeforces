import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.BitSet;
import java.io.BufferedReader;
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
        CPolycarpRestoresPermutation solver = new CPolycarpRestoresPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPolycarpRestoresPermutation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] q = in.readIntArray(n - 1);
            int min = 0, max = 0;
            int x = 0;
            for (int i : q) {
                x += i;
                min = Math.min(min, x);
                max = Math.max(max, x);
            }
            int start = -min;
            int[] answer = new int[n];
            answer[0] = start + 1;
            for (int i = 0; i < n - 1; i++) {
                answer[i + 1] = answer[i] + q[i];
            }
            BitSet used = new BitSet();
            for (int i : answer) {
                if (i <= 0 || i > n || used.get(i)) {
                    out.println(-1);
                    return;
                }
                used.set(i);
            }
            out.println(Util.join(answer));
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