import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            ArraysUtils.sort(a);
            IntPair[] b = new IntPair[n];
            for (int i = 0; i < n; ++i) {
                b[i] = new IntPair(in.nextInt(), i);
            }
            Arrays.sort(b);
            int[] fans = new int[n];
            for (int i = 0; i < n; ++i) {
                fans[b[i].second] = a[n - i - 1];
            }
            for (int i = 0; i < n; ++i) {
                out.print(fans[i] + " ");
            }
            out.println();
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

    static class ArraysUtils {
        private static Random rnd = new Random();

        public static void randomShuffle(int[] a, int from, int to) {
            for (int i = from; i < to; ++i) {
                int pos = i + rnd.nextInt(to - i);
                swap(a, i, pos);
            }
        }

        public static void sort(int[] a, int from, int to) {
            randomShuffle(a, from, to);
            Arrays.sort(a, from, to);
        }

        public static void sort(int[] a) {
            sort(a, 0, a.length);
        }

        public static void swap(int[] a, int i, int j) {
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }

    }

    static class IntPair implements Comparable<IntPair> {
        public int first;
        public int second;

        public IntPair() {
        }

        public IntPair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(IntPair other) {
            if (first != other.first) return first < other.first ? -1 : 1;
            if (second != other.second) return second < other.second ? -1 : 1;
            return 0;
        }

        public boolean equals(Object other) {
            if (!(other instanceof IntPair)) return false;
            return compareTo((IntPair) other) == 0;
        }

        public int hashCode() {
            return first * 31 + second;
        }

    }
}