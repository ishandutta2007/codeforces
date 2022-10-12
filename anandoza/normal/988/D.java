import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
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
        DPointsAndPowersOfTwo solver = new DPointsAndPowersOfTwo();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPointsAndPowersOfTwo {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] xArr = in.readLongArray(n);

            HashSet<Long> x = new HashSet<>();
            for (long i : xArr) {
                x.add(i);
            }

            int answer = 1;
            long[] best = {xArr[0]};

            outer:
            for (long i : xArr) {
                for (long offset = 1; offset < 2_000_000_000; offset *= 2) {
                    if (x.contains(i + offset)) {
                        answer = 2;
                        best = new long[]{i, i + offset};
                        if (x.contains(i + 2 * offset)) {
                            answer = 3;
                            best = new long[]{i, i + offset, i + 2 * offset};
                            break outer;
                        }
                    }
                }
            }

            out.println(answer);
            out.println(Util.join(best));
        }

    }

    static class Util {
        public static String join(long... i) {
            StringBuilder sb = new StringBuilder();
            for (long o : i) {
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}