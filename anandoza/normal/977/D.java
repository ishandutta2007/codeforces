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
        DDivideByThreeMultiplyByTwo solver = new DDivideByThreeMultiplyByTwo();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDivideByThreeMultiplyByTwo {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.readLongArray(n);

            List<Long> answer = new ArrayList<>();

            long first = 1;
            long three = 0, two = 1000;
            for (long x : a) {
                long orig = x;
                int th = 0, tw = 0;
                while (x % 2 == 0) {
                    x /= 2;
                    tw++;
                }
                while (x % 3 == 0) {
                    x /= 3;
                    th++;
                }

                if (th > three || tw < two) {
                    three = th;
                    two = tw;
                    first = orig;
                }
            }

            answer.add(first);

            while (answer.size() < n) {
                for (long x : a) {
                    if (x * 3 == answer.get(answer.size() - 1) || x == answer.get(answer.size() - 1) * 2) {
                        answer.add(x);
                        break;
                    }
                }
            }

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