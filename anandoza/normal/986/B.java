import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.BitSet;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        BPetrAndPermutations solver = new BPetrAndPermutations();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPetrAndPermutations {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = Permutations.readPermutation(in, n);

            out.println(Permutations.isOdd(p) == (n % 2 == 1) ? "Petr" : "Um_nik");
        }

    }

    static class Permutations {
        public static int[] readPermutation(InputReader in, int n) {
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }
            return p;
        }

        public static boolean isOdd(int[] permutation) {
            return isOdd(findCycles(permutation));
        }

        public static boolean isOdd(List<List<Integer>> cycles) {
            boolean parity = false;
            for (List<Integer> c : cycles) {
                parity ^= (c.size() % 2 == 0);
            }
            return parity;
        }

        public static List<List<Integer>> findCycles(int[] permutation) {
            List<List<Integer>> cycles = new ArrayList<>();
            int n = permutation.length;
            BitSet visited = new BitSet(n);

            for (int i = 0; i < n; i++) {
                if (visited.get(i))
                    continue;

                List<Integer> c = new ArrayList<>();
                for (int j = i; c.isEmpty() || j != i; j = permutation[j]) {
                    c.add(j);
                    visited.set(j);
                }

                if (c.size() > 1) {
                    cycles.add(c);
                }
            }

            return cycles;
        }

        private Permutations() {
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
}