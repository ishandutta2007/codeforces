import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Deque;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Objects;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.util.ArrayDeque;
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
        BFridgeLockers solver = new BFridgeLockers();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFridgeLockers {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] a = in.readIntArray(n);

            List<Pair<Integer, Integer>> edges = findEdges(a, m);
            if (edges == null) {
                out.println(-1);
                return;
            }

            int cost = findCost(a, edges);
            out.println(cost);
            for (Pair<Integer, Integer> e : edges) {
                out.println(Util.join(e.first + 1, e.second + 1));
            }
            Util.ASSERT(verifyDegrees(n, m, edges));
            Util.ASSERT(cost == findTheoreticalMin(a, m));
        }

        private static boolean verifyDegrees(int n, int m, List<Pair<Integer, Integer>> edges) {
            HashSet<Integer>[] neighbors = new HashSet[n];
            for (int i = 0; i < n; i++) {
                neighbors[i] = new HashSet<>();
            }
            for (Pair<Integer, Integer> e : edges) {
                neighbors[e.first].add(e.second);
                neighbors[e.second].add(e.first);
            }

            if (edges.size() != m) {
                return false;
            }

            for (HashSet<Integer> s : neighbors) {
                if (s.size() < 2) {
                    return false;
                }
            }

            return true;
        }

        private static int findCost(int[] a, List<Pair<Integer, Integer>> edges) {
            int cost = 0;
            for (Pair<Integer, Integer> e : edges) {
                cost += a[e.first];
                cost += a[e.second];
            }
            return cost;
        }

        private static int findTheoreticalMin(int[] a, int m) {
            int n = a.length;
            int[] s = a.clone();
            Arrays.sort(s);

            Util.ASSERT(m >= n);

            int min = s[0];
            int min2 = s[1];
            int tot = 0;
            for (int x : s) {
                tot += x;
            }

            int cost = 0;
            cost += 2 * tot; // deg(each) >= 2

            // deg(min) <= sum[deg(rest)] therefore deg(min) <= totaldeg - deg(min)
            // therefore 2deg(min) <= totaldeg = m * 2
            // every node has at least 1 edge not including min. so there are at least
            // n-1 unavailable degree. so deg(min) <= 2*m - (n-1) - deg(min)
            // deg(min) <= m - (n-1)/2
            int deg2OfEach = 2 * (n - 1);
            int degMin = Math.min(m - (n - 1 + 1) / 2, 2 * m - deg2OfEach);
            cost += (degMin - 2) * min;
            int degMin2 = 2 * m - 2 * (n - 2) - degMin;
            cost += (degMin2 - 2) * min2;
            return cost;
        }

        private static List<Pair<Integer, Integer>> findEdges(int[] a, int m) {
            int n = a.length;
            if (n <= 2 || m < n) {
                return null;
            }

            if (n == m) {
                List<Pair<Integer, Integer>> answer = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    answer.add(Pair.of(i, (i + 1) % n));
                }
                return answer;
            }

            Integer[] indices = new Integer[n];
            for (int i = 0; i < n; i++) {
                indices[i] = i;
            }
            Arrays.sort(indices, Comparator.comparingInt((Integer i) -> a[i]));
            Deque<Integer> big = new ArrayDeque<>();
            for (int i = 2; i < n; i++) {
                big.add(indices[i]);
            }
            int min = indices[0];
            int min2 = indices[1];
            int degMin = Math.min(m - (n - 1 + 1) / 2, 2 * m - 2 * (n - 1));
            int degMin2 = 2 * m - 2 * (n - 2) - degMin;
            //System.out.format("n=%d, m=%d, degMin=%d, degMin2=%d%n", n, m, degMin, degMin2);

            List<Pair<Integer, Integer>> answer = new ArrayList<>();
            while (degMin2 > 2) {
                answer.add(Pair.of(min, min2));
                degMin--;
                degMin2--;
            }
            while (degMin > 2) {
                if (big.size() < 2)
                    break;

                int i = big.pollFirst(), j = big.pollFirst();
                answer.add(Pair.of(min, i));
                answer.add(Pair.of(min, j));
                answer.add(Pair.of(i, j));
                degMin -= 2;
            }

            List<Integer> remaining = new ArrayList<>();
            remaining.addAll(big);
            remaining.add(min);
            remaining.add(min2);
            Util.ASSERT(degMin == 2);
            Util.ASSERT(degMin2 == 2);
            Util.ASSERT(m - answer.size() == remaining.size());

            for (int i = 0; i < remaining.size(); i++) {
                answer.add(Pair.of(remaining.get(i), remaining.get((i + 1) % remaining.size())));
            }

            return answer;
        }

    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
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

        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }
}