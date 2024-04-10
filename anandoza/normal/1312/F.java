import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.function.LongBinaryOperator;
import java.util.function.IntBinaryOperator;
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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FAttackOnRedKingdom solver = new FAttackOnRedKingdom();
        solver.solve(1, in, out);
        out.close();
    }

    static class FAttackOnRedKingdom {
        int[][][][] allPrecomputedNimbers;
        private static final int O = 0;
        private static final int A = 1;
        private static final int B = 2;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            allPrecomputedNimbers = new int[5][5][5][];

            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int x = in.nextInt(), y = in.nextInt(), z = in.nextInt();
            long[] a = in.readLongArray(n);

            if (allPrecomputedNimbers[x - 1][y - 1][z - 1] == null)
                allPrecomputedNimbers[x - 1][y - 1][z - 1] = precomputeNimbers(x, y, z);
            int[] precomp = allPrecomputedNimbers[x - 1][y - 1][z - 1];

            LongBinaryOperator nimber = (defenders, lastAttack) -> {
                if (defenders <= 0)
                    return 0;
                long key = 3 * defenders + lastAttack;
                if (key < precomp.length)
                    return precomp[(int) key];

                key %= precomp.length / 2;
                key += precomp.length / 2;

                return precomp[(int) key];
            };

            int[] nimbers = new int[n];
            for (int i = 0; i < n; i++) {
                nimbers[i] = (int) nimber.applyAsLong(a[i], O);
            }
            int xor = 0;
            for (int i : nimbers)
                xor ^= i;

            int answer = 0;
            for (int i = 0; i < n; i++) {
                if ((nimber.applyAsLong(a[i] - x, O) ^ nimbers[i] ^ xor) == 0)
                    answer++;
                if ((nimber.applyAsLong(a[i] - y, A) ^ nimbers[i] ^ xor) == 0)
                    answer++;
                if ((nimber.applyAsLong(a[i] - z, B) ^ nimbers[i] ^ xor) == 0)
                    answer++;
            }

            out.println(answer);
        }

        private int[] precomputeNimbers(int x, int y, int z) {
            List<Integer> nimbers = new ArrayList<>();
            nimbers.add(0);
            nimbers.add(0);
            nimbers.add(0);

            IntBinaryOperator nimber = (defenders, lastAttack) -> {
                if (defenders <= 0)
                    return 0;
                return nimbers.get(3 * defenders + lastAttack);
            };

            while (true) {
                int n = nimbers.size();
                int defenders = n / 3;
                int lastAttack = n % 3;

                List<Integer> reachable = new ArrayList<>();
                reachable.add(nimber.applyAsInt(defenders - x, O));
                if (lastAttack != A)
                    reachable.add(nimber.applyAsInt(defenders - y, A));
                if (lastAttack != B)
                    reachable.add(nimber.applyAsInt(defenders - z, B));

                nimbers.add(Util.mex(reachable));

                if (nimbers.size() % 30 == 0) {
                    int blocks = nimbers.size() / 30;
                    List<Integer> list1 = nimbers.subList(blocks * 15 - 15, blocks * 15);
                    List<Integer> list2 = nimbers.subList(blocks * 30 - 15, blocks * 30);
                    if (list1.equals(list2)) {
                        break;
                    }
                }
            }

            int[] array = new int[nimbers.size()];
            for (int i = 0; i < array.length; i++) {
                array[i] = nimbers.get(i);
            }

            return array;
        }

    }

    static class Util {
        private Util() {
        }

        public static int mex(Iterable<Integer> x) {
            BitSet bs = new BitSet();
            for (int i : x)
                bs.set(i);
            return bs.nextClearBit(0);
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