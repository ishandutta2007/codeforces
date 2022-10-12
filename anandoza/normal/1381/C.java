import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.BitSet;
import java.util.Comparator;
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
        CMastermind solver = new CMastermind();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMastermind {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), x = in.nextInt(), y = in.nextInt();
            int[] b = Permutations.readPermutation(in, n);
            int missing = Util.mex(b);

            List<Integer>[] locations = Util.arrayOfLists(n + 1);
            for (int i = 0; i < n; i++) {
                locations[b[i]].add(i);
            }

            PriorityQueue<Pii> items = new PriorityQueue<>(Comparator.comparingInt(p -> -p.second));
            Counter<Integer> count = new Counter<>();
            for (int i = 0; i < n; i++) {
                count.incr(b[i]);
            }
            for (Map.Entry<Integer, Integer> e : count.count.entrySet())
                items.add(Pii.of(e.getKey(), e.getValue()));

            int[] a = b.clone();

            int yPrime = 0;

            while (true) {
                if (items.size() < 2)
                    break;

                Pii first = items.poll(), second = items.poll();

                List<Integer> cycle = new ArrayList<>();
                cycle.add(first.first);
                cycle.add(second.first);

                if (yPrime + cycle.size() > n - x)
                    break;

                if (yPrime + cycle.size() + 2 > n - x && yPrime + cycle.size() + 1 == y - x) {
                    if (!items.isEmpty()) {
                        Pii third = items.poll();
                        cycle.add(third.first);
                        if (third.second - 1 > 0)
                            items.add(Pii.of(third.first, third.second - 1));
                    }
                }
                if (first.second - 1 > 0)
                    items.add(Pii.of(first.first, first.second - 1));
                if (second.second - 1 > 0)
                    items.add(Pii.of(second.first, second.second - 1));

                List<Integer> loc = new ArrayList<>();
                for (int i : cycle) {
                    loc.add(locations[i].remove(locations[i].size() - 1));
                }

                for (int i = 0; i < loc.size(); i++) {
                    a[loc.get(i)] = b[loc.get((i + 1) % loc.size())];
                }
                yPrime += loc.size();
                if (yPrime >= y - x)
                    break;
            }

            //System.out.println("a = " + Arrays.toString(a));
            if (/*yPrime > n - x ||*/ yPrime < y - x) {
                out.println("NO");
                return;
            }

            int closeToWrong = yPrime - (y - x);
            for (int i = 0; i < n && closeToWrong > 0; i++) {
                if (a[i] != b[i]) {
                    a[i] = missing;
                    closeToWrong--;
                }
            }
            //System.out.println("closeToWrong = " + closeToWrong);
            int rightToWrong = n - yPrime - x;
            for (int i = 0; i < n && rightToWrong > 0; i++) {
                if (a[i] == b[i]) {
                    a[i] = missing;
                    rightToWrong--;
                }
            }
            //System.out.println("rightToWrong = " + rightToWrong);

            out.println("YES");
            for (int i = 0; i < n; i++) {
                a[i]++;
                b[i]++;
            }
            out.println(Util.join(a));
            //out.println(Util.join(b));
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

    static class Permutations {
        public static int[] readPermutation(InputReader in, int n) {
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }
            return p;
        }

        private Permutations() {
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

        public static int mex(int... x) {
            BitSet bs = new BitSet();
            for (int i : x)
                bs.set(i);
            return bs.nextClearBit(0);
        }

        public static <T> List<T>[] arrayOfLists(int n) {
            List<T>[] array = new List[n];
            for (int i = 0; i < n; i++) {
                array[i] = new ArrayList<>();
            }
            return array;
        }

    }

    static class Counter<T> {
        public final HashMap<T, Integer> count = new HashMap<>();

        public Counter() {
        }

        public Counter(T[] elements) {
            for (T t : elements)
                incr(t);
        }

        public Counter(Iterable<T> elements) {
            for (T t : elements)
                incr(t);
        }

        public void incr(T key) {
            count.merge(key, 1, Integer::sum);
        }

    }

    static class Pii implements Comparable<Pii> {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pii o) {
            if (first != o.first)
                return Integer.compare(first, o.first);
            return Integer.compare(second, o.second);
        }

    }
}