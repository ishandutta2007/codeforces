import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.TreeSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int N = in.nextInt(), Q = in.nextInt();

            long left = 1L << N - 1, right = 2 * left - 1;

            TreeSet<Pair<Long, Long>> S = new TreeSet<>();
            S.add(Pair.make_pair(left, right));

            while (Q-- > 0) {
                int h = in.nextInt();
                long L = in.nextLong(), R = in.nextLong();
                int p = in.nextInt();

                if (L > R) {
                    if (p == 1) S.clear();
                    continue;
                }

                long first = L << (N - h), last = (R << (N - h)) + (1L << (N - h)) - 1;
                if (p == 1) {
                    while (!S.isEmpty()) {
                        if (S.first().second < first) S.pollFirst();
                        else break;
                    }
                    while (!S.isEmpty()) {
                        if (S.last().first > last) S.pollLast();
                        else break;
                    }

                    if (!S.isEmpty() && S.first().first < first)
                        S.first().first = first;
                    if (!S.isEmpty() && S.last().second > last)
                        S.last().second = last;
                } else {
                    Pair<Long, Long> c = Pair.make_pair(first, -1L);
                    Pair<Long, Long> laste = c;
                    while (true) {
                        Pair<Long, Long> curr = S.ceiling(laste);
                        if (curr == null || curr.second > last) break;
                        S.remove(curr);
                        laste = curr;
                    }

                    laste = S.ceiling(c);
                    if (laste != null && laste.first <= last)
                        laste.first = last + 1;

                    laste = S.lower(c);
                    if (laste != null && laste.second >= first) {
                        if (laste.second <= last) laste.second = first - 1;
                        else {
                            long l1 = laste.first, r1 = first - 1;
                            long l2 = last + 1, r2 = laste.second;
                            S.remove(laste);
                            S.add(Pair.make_pair(l1, r1));
                            S.add(Pair.make_pair(l2, r2));
                        }
                    }
                }
            }

            if (S.isEmpty()) out.println("Game cheated!");
            else if (S.size() > 1 || S.first().first.longValue() != S.first().second)
                out.println("Data not sufficient!");
            else out.println(S.first().first);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new UnknownError();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuffer res = new StringBuffer();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));

            return res.toString();
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Pair<T, V> implements Comparable<Pair<T, V>> {
        public T first;
        public V second;

        public static <T, V> Pair<T, V> make_pair(T first, V second) {
            return new Pair(first, second);
        }

        public Pair() {
        }

        private Pair(T first, V second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair<T, V> other) {
            int comp = ((Comparable<T>) first).compareTo(other.first);
            if (comp != 0) return comp;
            return ((Comparable<V>) second).compareTo(other.second);
        }

        public boolean equals(Object other) {
            if (this == other) return true;
            if (other == null || getClass() != other.getClass()) return false;

            Pair pair = (Pair) other;

            return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);
        }

        public int hashCode() {
            int h1 = first == null ? 0 : first.hashCode();
            int h2 = second == null ? 0 : second.hashCode();
            return 31 * h1 + h2;
        }

    }
}