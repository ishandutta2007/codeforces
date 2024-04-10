import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.IOException;
import java.util.Collections;
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            List<Pairii> A = new ArrayList<>(), B = new ArrayList<>();

            int N = in.nextInt();
            for (int i = 0; i < N; ++i) {
                int x = in.nextInt(), a = in.nextInt();
                if (x < 0) A.add(new Pairii(-x, a));
                else B.add(new Pairii(x, a));
            }

            int lim = Math.min(A.size(), B.size()) + 1;
            Collections.sort(A);
            Collections.sort(B);

            long ans = 0;
            for (int i = 0; i < lim; ++i) {
                if (i < A.size()) ans += A.get(i).second;
                if (i < B.size()) ans += B.get(i).second;
            }

            out.println(ans);
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

    static class Pairii implements Comparable<Pairii> {
        public int first;
        public int second;

        public Pairii() {
        }

        public Pairii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pairii other) {
            if (first != other.first) return first < other.first ? -1 : 1;
            if (second != other.second) return second < other.second ? -1 : 1;
            return 0;
        }

        public boolean equals(Object other) {
            if (!(other instanceof Pairii)) return false;
            return compareTo((Pairii) other) == 0;
        }

        public int hashCode() {
            return first * 31 + second;
        }

    }
}