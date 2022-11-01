import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            if (n == 2) {
                out.println("3\n2 1 2");
                return;
            }
            if (n <= 4) {
                out.println(2 * n - 2);
                for (int i = 2; i <= n; ++i) {
                    out.print(i + " ");
                }
                for (int i = 1; i < n; ++i) {
                    out.print(i + " ");
                }
                out.println();
            } else {
                IntList mid = new IntList();
                IntList left = new IntList();
                for (int i = 1; i <= n; ++i) {
                    if (i % 2 != 0) {
                        mid.add(i);
                    } else {
                        left.add(i);
                    }
                }
                IntList res = new IntList();
                left.reverse();
                for (int val : left) {
                    res.add(val);
                }
                for (int val : mid) {
                    res.add(val);
                }
                left.reverse();
                for (int val : left) {
                    res.add(val);
                }
                out.println(res.size());
                for (int val : res) {
                    out.print(val + " ");
                }
                out.println();
            }
        }

    }

    static class ArraysUtils {
        public static void swap(int[] a, int i, int j) {
            int aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }

        public static void reverse(int[] a, int left, int right) {
            while (left < right - 1)
                swap(a, left++, --right);
        }

    }

    static class IntList implements Iterable<Integer> {
        int[] elem;
        int size;

        public IntList() {
            this(0, 0, 1);
        }

        public IntList(int size) {
            this(size, 0, Math.max(1, size));
        }

        public IntList(int size, int value) {
            this(size, value, Math.max(1, size));
        }

        public IntList(int size, int value, int capacity) {
            elem = new int[capacity];
            Arrays.fill(elem, 0, size, value);
            this.size = size;
        }

        private IntList(int... e) {
            elem = e.clone();
            size = e.length;
        }

        public void add(int e) {
            if (size + 1 > elem.length) {
                increaseCapacity();
            }
            elem[size++] = e;
        }

        private void increaseCapacity() {
            changeCapacity(3 * elem.length / 2 + 1);
        }

        private void changeCapacity(int newCapacity) {
            int[] nElem = new int[newCapacity];
            System.arraycopy(elem, 0, nElem, 0, Math.min(elem.length, newCapacity));
            elem = nElem;
        }

        public void reverse() {
            reverse(0, size);
        }

        public void reverse(int from, int to) {
            ArraysUtils.reverse(elem, from, to);
        }

        public IntIterator iterator() {
            return new IntIterator() {
                int pos = 0;


                public Integer next() {
                    return IntList.this.elem[pos++];
                }


                public boolean hasNext() {
                    return pos < IntList.this.size;
                }


                public int nextInt() {
                    return IntList.this.elem[pos++];
                }
            };
        }

        public int size() {
            return size;
        }

        public int hashCode() {
            int hashCode = 0;
            for (int i = 0; i < size; ++i) {
                hashCode = 31 * hashCode + elem[i];
            }
            return hashCode;
        }

    }

    static interface IntIterator extends Iterator<Integer> {
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