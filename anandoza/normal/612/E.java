import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
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
        ESquareRootOfPermutation solver = new ESquareRootOfPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESquareRootOfPermutation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p = Permutations.readPermutation(n, in);

            List<List<Integer>> originalCycles = Permutations.findCycles(p);
            HashMap<Integer, List<List<Integer>>> cyclesByLength = new HashMap<>();
            for (List<Integer> c : originalCycles) {
                int l = c.size();
                if (!cyclesByLength.containsKey(l))
                    cyclesByLength.put(l, new ArrayList<>());
                cyclesByLength.get(l).add(c);
            }

            List<List<Integer>> sqrtCycles = new ArrayList<>();
            for (Map.Entry<Integer, List<List<Integer>>> e : cyclesByLength.entrySet()) {
                int len = e.getKey();
                List<List<Integer>> cycles = e.getValue();

                if (len % 2 == 1) {
                    for (List<Integer> c : cycles) {
                        List<Integer> sq = new ArrayList<>();
                        int k = len / 2;
                        for (int i = 0; i < k; i++) {
                            sq.add(c.get(i));
                            sq.add(c.get(i + k + 1));
                        }
                        sq.add(c.get(k));
                        sqrtCycles.add(sq);
                    }
                } else {
                    if (cycles.size() % 2 == 1) {
                        out.println(-1);
                        return;
                    }
                    for (int i = 0; i < cycles.size(); i += 2) {
                        List<Integer> a = cycles.get(i);
                        List<Integer> b = cycles.get(i + 1);
                        List<Integer> sq = new ArrayList<>();
                        for (int j = 0; j < len; j++) {
                            sq.add(a.get(j));
                            sq.add(b.get(j));
                        }
                        sqrtCycles.add(sq);
                    }
                }
            }

            int[] answer = Permutations.fromCycles(n, sqrtCycles);
            for (int i = 0; i < answer.length; i++)
                answer[i]++;

            out.println(Util.join(answer));
        }

    }

    static class Permutations {
        public static int[] readPermutation(int n, InputReader in) {
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }
            return p;
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

        public static int[] fromCycles(int n, List<List<Integer>> cycles) {
            int[] p = new int[n];
            Arrays.fill(p, -1);
            for (List<Integer> c : cycles) {
                for (int i = 0; i + 1 < c.size(); i++) {
                    p[c.get(i)] = c.get(i + 1);
                }
                p[c.get(c.size() - 1)] = c.get(0);
            }
            for (int i = 0; i < n; i++) {
                if (p[i] == -1)
                    p[i] = i;
            }
            return p;
        }

        private Permutations() {
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

    }
}