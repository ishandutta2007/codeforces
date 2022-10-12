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
import java.util.BitSet;
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
        DReplaceByMEX solver = new DReplaceByMEX();
        solver.solve(1, in, out);
        out.close();
    }

    static class DReplaceByMEX {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            List<Integer> answer = solve(a);

            Util.ASSERT(answer.size() <= 2 * n);
            out.println(answer.size());
            out.println(Util.join(answer));
        }

        private static int mex(int[] a) {
            BitSet s = new BitSet();
            for (int x : a)
                s.set(x);
            return s.nextClearBit(0);
        }

        private static void apply(int[] a, List<Integer> moves, int move) {
            a[move] = mex(a);
            moves.add(move + 1);
        }

        private static List<Integer> solve(int[] a) {
            final int n = a.length;

            List<Integer> moves = new ArrayList<>();

//        System.out.println("progress a = " + Arrays.toString(a));
//        for (int i = 0; i < n; i++) {
//            apply(a, moves, i);
//        }

            int first = 0, last = n;

            while (first < last) {
//            System.out.println("progress a = " + Arrays.toString(a));
                int mex = mex(a);

                if (mex >= last) {
                    mex = last - 1;
                    apply(a, moves, mex);
                    last--;
                    while (last > first && a[last - 1] == a[last] - 1)
                        last--;
                    continue;
                }
                if (mex <= first) {
                    mex = first;
                    apply(a, moves, mex);
                    first++;
                    while (first < last && a[first] == a[first - 1] + 1)
                        first++;
                    continue;
                }

                apply(a, moves, mex);
            }

            return moves;
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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
}