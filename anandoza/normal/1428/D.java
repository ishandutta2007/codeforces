import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
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
        DBouncingBoomerangs solver = new DBouncingBoomerangs();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBouncingBoomerangs {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            Queue<Integer>[] q = new Queue[4];
            for (int i = 0; i < 4; i++) {
                q[i] = new ArrayDeque<>();
            }
            for (int i = 0; i < n; i++) {
                q[a[i]].add(i);
            }

            int row = 0;
            List<Pii> ans = new ArrayList<>();
            int[] count = new int[n];

            for (int i = 0; i < n; i++) {
                if (!q[a[i]].isEmpty() && q[a[i]].peek() == i)
                    q[a[i]].poll();
                switch (a[i]) {
                    case 0:
                        // do nothing
                        break;
                    case 1:
                        if (count[i] == 0) {
                            ans.add(Pii.of(row, i));
                            row++;
                        }
                        break;
                    case 2: {
                        if (q[1].isEmpty()) {
                            out.println(-1);
                            return;
                        }
                        int one = q[1].poll();
                        count[one]++;
                        ans.add(Pii.of(row, i));
                        ans.add(Pii.of(row, one));
                        row++;
                        break;
                    }
                    case 3: {
                        if (!q[2].isEmpty() || !q[3].isEmpty()) {
                            int next = q[2].isEmpty() ? q[3].poll() : q[3].isEmpty() ? q[2].poll()
                                                                                     : q[2].peek() < q[3].peek()
                                                                                       ? q[2].poll() : q[3].poll();
                            ans.add(Pii.of(row, i));
                            ans.add(Pii.of(row, next));
                            row++;
                        } else if (!q[1].isEmpty()) {
                            int one = q[1].poll();
                            ans.add(Pii.of(row, i));
                            ans.add(Pii.of(row, one));
                            ans.add(Pii.of(row + 1, one));
                            count[one]++;
                            row += 2;
                        } else {
                            out.println(-1);
                            return;
                        }
                        break;
                    }
                }
            }

            out.println(ans.size());
            for (Pii p : ans) {
                out.println(Util.join(p.first + 1, p.second + 1));
                // System.out.format("(%d, %d)%n", p.second + 1, n - p.first + 0);
            }
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