import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.function.IntConsumer;
import java.io.IOException;
import java.util.Deque;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
        A2PrefixFlipHardVersion solver = new A2PrefixFlipHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class A2PrefixFlipHardVersion {
        int n;
        int[] a;
        int[] b;
        int[] debug;
        private static final boolean DEBUG = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            n = in.nextInt();
            a = in.readBitString();
            b = in.readBitString();
            if (DEBUG)
                debug = a.clone();

            Deque<Integer> answer = new ArrayDeque<>();

            IntConsumer flip = i -> {
                if (DEBUG) {
                    for (int j = 0; j < i; j++) {
                        debug[j] ^= 1;
                    }
                    for (int j = 0; j < i - 1 - j; j++) {
                        Util.swap(debug, j, i - 1 - j);
                    }
                }
                answer.add(i);
            };

            int first = 0, last = n - 1;
            for (int i = n - 1; i >= 1; i--) {
                int cur = (n - 1 - i) % 2 == 0 ? first : last;
                int parity = (n - 1 - i) % 2;

                if ((a[cur] ^= parity) == b[i])
                    flip.accept(1);

                flip.accept(i + 1);

                if (cur == first)
                    first++;
                else
                    last--;
            }

            if ((a[first] ^ ((n - 1) % 2)) != b[0])
                flip.accept(1);

            if (DEBUG) {
                System.out.println("    a = " + Arrays.toString(a));
                System.out.println("debug = " + Arrays.toString(debug));
                System.out.println("    b = " + Arrays.toString(b));
            }

            out.print(answer.size() + " ");
            out.println(Util.join(answer));
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

        public static void swap(int[] x, int i, int j) {
            int t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        private Util() {
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

        public int[] readBitString() {
            char[] chars = next().toCharArray();
            int[] x = new int[chars.length];
            for (int i = 0; i < x.length; i++) {
                x[i] = chars[i] - '0';
            }
            return x;
        }

    }
}