import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        DStrangeDevice solver = new DStrangeDevice();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStrangeDevice {
        private int n;
        private int k;
        private int usedGuessCount = 0;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            k = in.nextInt();

            if (k == 1) {
                answer(0);
                return;
            }

            int[] x = new int[k];
            long[] a = new long[n];
            Arrays.fill(a, -1);
            for (int i = 0; i < k; i++) {
                x[i] = i;
            }

            for (int next = k; next <= n; next++) {
                Pair<Integer, Long> res = query(x);
                int last = res.first;
                a[last] = res.second;

                if (next != n)
                    for (int i = 0; i < k; i++) {
                        if (x[i] == last)
                            x[i] = next;
                    }
            }
            //System.out.println(Arrays.toString(a));
            if (n - k + 1 >= k) {
                int[] lastQuery = new int[k];
                int index = 0;
                List<Long> values = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    if (a[i] < 0)
                        continue;
                    lastQuery[index++] = i;
                    values.add(a[i]);
                    if (index >= lastQuery.length)
                        break;
                }
                Pair<Integer, Long> res = query(lastQuery);
                Collections.sort(values);
                for (int i = 0; i < k; i++) {
                    if (res.second.equals(values.get(i))) {
                        answer(i);
                        return;
                    }
                }
            } else {
                int[] lastQuery = new int[k];
                //System.out.println("x: " + Arrays.toString(x));
                //System.out.println("blah3");
                for (int i = 0, index = 0; i < k; i++) {
                    if (a[x[i]] < 0)
                        lastQuery[index++] = x[i];
                }
                for (int i = 0; i < k; i++) {
                    if (a[x[i]] >= 0) {
                        lastQuery[k - 1] = x[i];
                    }
                }
                int fungible = -1;
                int fixed = lastQuery[k - 1];
                for (int i = 0; i < n; i++) {
                    if (a[i] >= 0 && a[i] != a[fixed]) {
                        fungible = i;
                        break;
                    }
                }
                int same = 0, diff = 0;
                for (int i = 0; i < k - 1; i++) {
                    int t = lastQuery[i];
                    lastQuery[i] = fungible;
                    Pair<Integer, Long> res = query(lastQuery);
                    if (res.first.equals(fixed)) {
                        same++;
                    } else {
                        diff++;
                    }
                    lastQuery[i] = t;
                }
                int left = a[fungible] < a[fixed] ? same : diff;
                int right = a[fungible] < a[fixed] ? diff : same;
                //System.out.println("LEFT + RIGHT: " + Util.join(left, right));

                //System.out.println("fun: " + fungible);
                //System.out.println("last query: " + Arrays.toString(lastQuery));
                //System.out.println("blah3");
                //System.out.println("last query: " + Arrays.toString(lastQuery));
                answer(left);
                return;
            }
        }

        private Pair<Integer, Long> query(int... x) {
            usedGuessCount++;
            int[] nx = new int[x.length];
            for (int i = 0; i < x.length; i++) {
                nx[i] = x[i] + 1;
            }
            out.println("? " + Util.join(nx));
            out.flush();
            return Pair.of(in.nextInt() - 1, in.nextLong());
        }

        private void answer(int x) {
            out.println("! " + (x + 1));
            out.flush();
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
}