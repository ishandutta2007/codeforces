import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Pair<Long, Long> segments[] = new Pair[n];

            int x1 = in.nextInt(), x2 = in.nextInt();

            for (int i = 0; i < n; ++i) {
                int a = in.nextInt(), b = in.nextInt();
                segments[i] = Pair.make_pair((long) x1 * a + b, (long) x2 * a + b);
            }

            Arrays.sort(segments);
            for (int i = 1; i < n; ++i)
                if (segments[i].second < segments[i - 1].second) {
                    out.println("YES");
                    return;
                }

            out.println("NO");
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
}