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
import java.io.BufferedReader;
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
        EZebraTower solver = new EZebraTower();
        solver.solve(1, in, out);
        out.close();
    }

    static class EZebraTower {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            HashMap<Integer, List<Pii>> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int c = in.nextInt();
                int s = in.nextInt();
                if (!map.containsKey(c))
                    map.put(c, new ArrayList<>(0));
                map.get(c).add(Pii.of(s, i + 1));
            }
            for (List<Pii> l : map.values()) {
                l.sort(Comparator.reverseOrder());
            }
            HashMap<Integer, List<Pii>> orig = new HashMap<>(map);

            Map<Integer, Long> tots = new HashMap<>();
            int cPrev = -1;
            int cPrev2 = -1;
            long tPrev = 0;
            long tPrev2 = 0;
            Pii best = null;
            long score = 0;
            for (int i = 0; i < n; i++) {
                List<Integer> toRemove = new ArrayList<>();

                int c1 = -1, c2 = -1;
                for (int c : map.keySet()) {
                    List<Pii> l = map.get(c);
                    if (l.size() <= i) {
                        toRemove.add(c);
                        continue;
                    }
                    tots.merge(c, (long) l.get(i).first, Long::sum);
                    long t = tots.get(c);

                    if (c1 == -1 || t >= tots.get(c1)) {
                        c2 = c1;
                        c1 = c;
                    } else if (c2 == -1 || t >= tots.get(c2)) {
                        c2 = c;
                    }
                }

                if (c1 == -1)
                    break;

                for (int c : toRemove) {
                    map.remove(c);
                }

                long t1 = tots.get(c1);
                long t2 = c2 == -1 ? Long.MIN_VALUE : tots.get(c2);

                List<Pll> p = new ArrayList<>();
                p.add(Pll.of(c1, t1));
                p.add(Pll.of(c2, t2));
                p.add(Pll.of(cPrev, tPrev));
                p.add(Pll.of(cPrev2, tPrev2));

                for (Pll a : p) {
                    for (Pll b : p) {
                        if (a.first == -1 || b.first == -1 || a.first == b.first)
                            continue;
                        long s = a.second + b.second;
                        if (s > score) {
                            best = Pii.of((int) a.first, (int) b.first);
                            score = s;
                        }
                    }
                }

                cPrev = c1;
                tPrev = t1;
                cPrev2 = c2;
                tPrev2 = t2;
            }

            out.println(score);
            List<Integer> ans = new ArrayList<>();
            List<Pii> l1 = orig.get(best.first);
            List<Pii> l2 = orig.get(best.second);
            for (int i = 0; i < l1.size() && i < l2.size() + 1; i++) {
                ans.add(l1.get(i).second);
                score -= l1.get(i).first;
                if (i < l2.size()) {
                    ans.add(l2.get(i).second);
                    score -= l2.get(i).first;
                }
            }
            out.println(ans.size());
            out.println(Util.join(ans));
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

        private Util() {
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

    static class Pll implements Comparable<Pll> {
        public final long first;
        public final long second;

        public Pll(long first, long second) {
            this.first = first;
            this.second = second;
        }

        public static Pll of(long first, long second) {
            return new Pll(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pll pair = (Pll) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new long[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

        public int compareTo(Pll o) {
            if (first != o.first)
                return Long.compare(first, o.first);
            return Long.compare(second, o.second);
        }

    }
}