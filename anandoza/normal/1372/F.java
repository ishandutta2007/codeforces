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
        FOmkarAndModes solver = new FOmkarAndModes();
        solver.solve(1, in, out);
        out.close();
    }

    static class FOmkarAndModes {
        private InputReader in;
        private PrintWriter out;
        private int n;
        private int[] answer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();

            answer = new int[n];

            solve(0, n);

            out.println("! " + Util.join(answer));
            out.flush();
        }

        private void solve(int left, int right) {
            if (right - left <= 0)
                return;

            Pii mode = query(left, right);
            solve(left, right, mode);
        }

        private void solve(int left, int right, Pii mode) {
            if (right - left <= 0)
                return;

            int x = mode.first, f = mode.second;

            if (f == 1) {
                answer[left] = x;
                for (int i = left + 1; i < right; i++) {
                    answer[i] = query(i);
                }
                return;
            }

            if (f == right - left) {
                for (int i = left; i < right; i++) {
                    answer[i] = x;
                }
                return;
            }

            List<Pair<Pii, Pii>> q = new ArrayList<>();
            int start = -1, end = -1;
            for (int i = left; i < right; i += f) {
                int boxStart = i;
                int boxEnd = Math.min(right, i + f);
                if (end != -1)
                    boxStart = Math.max(boxStart, end);
                if (boxEnd <= boxStart)
                    continue;

                Pii boxMode = query(boxStart, boxEnd);

                if (boxMode.first == x) {
                    int count = boxMode.second;

                    if (count == f) {
                        start = boxStart;
                        end = boxEnd;
                    } else if (query(boxStart - 1) == x) {
                        end = boxStart + count;
                        start = end - f;
                    } else if (query(boxEnd) == x) {
                        start = boxEnd - count;
                        end = start + f;
                    }

                    for (int j = start; j < end; j++) {
                        answer[j] = x;
                    }

                    solve(boxStart, start);
                    solve(end, boxEnd);
                } else {
                    q.add(Pair.of(Pii.of(boxStart, boxEnd), boxMode));
                }
            }
            for (Pair<Pii, Pii> item : q) {
                int l = item.first.first, r = item.first.second;

                if (l <= start && start < r) {
                    r = start;
                }
                if (l <= end && end < r) {
                    l = end;
                }
                solve(l, r, item.second);
            }
        }

        private int query(int i) {
            if (i < 0 || i >= n)
                return -1;

            return query(i, i + 1).first;
        }

        private Pii query(int l, int r) {
            out.println("? " + (l + 1) + " " + r);
            out.flush();
            int x = in.nextInt(), f = in.nextInt();
            return Pii.of(x, f);
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