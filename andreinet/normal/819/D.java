import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt(), n = in.nextInt();
            int sum = 0;
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                a[i] %= T;
                sum = (sum + a[i]) % T;
            }
            int first = a[0];
            for (int i = 0; i < n - 1; ++i) {
                a[i] = a[i + 1];
            }
            a[n - 1] = first;
            int cycles = gcd(T, sum);
            int cycleLen = T / cycles;
            int[] b = new int[n];
            for (int i = 1; i < n; ++i) {
                b[i] = (b[i - 1] + a[i - 1]) % T;
            }
            for (int i = 0; i < n; ++i) {
                a[i] = b[i];
            }
            int[] inds = new int[n];
            for (int i = 0; i < n; ++i) {
                inds[i] = i;
            }
            ArraysUtils.randomShuffle(inds);
            Integer[] pInds = new Integer[n];
            for (int i = 0; i < n; ++i) {
                pInds[i] = inds[i];
            }
            Arrays.sort(pInds, (o1, o2) -> Integer.compare(a[o1] % cycles, a[o2] % cycles));
            for (int i = 0; i < n; ++i) {
                inds[i] = pInds[i];
            }
            int[] ans = new int[n];
            int sqrt = (int) Math.sqrt(cycleLen * (long) n) + 2;
            int[] posInCycle = new int[n];
            for (int i = 0, j; i < n; i = j) {
                j = i;
                while (j < n && a[inds[i]] % cycles == a[inds[j]] % cycles) {
                    j++;
                }
                int rem = a[inds[i]] % cycles;
//            Map<Integer, Integer> pos = new TreeMap<>();
//            int cnt = 0, cPos = 0;
//            for (int x = rem; cnt < sqrt && !pos.containsKey(x); x = (int) (x + (long) sqrt * sum) % T) {
//                pos.put(x, cPos);
//                cnt++;
//                cPos += sqrt;
//                cPos %= cycleLen;
//            }
//            for (int k = i; k < j; ++k) {
//                int sub = 0;
//                int key = a[inds[k]] % T;
//                while (!pos.containsKey(key)) {
//                    sub++;
//                    key += sum;
//                    key %= T;
//                }
//                posInCycle[inds[k]] = (pos.get(key) - sub + cycleLen) % cycleLen;
//            }
                for (int k = i; k < j; ++k) {
                    int key = a[inds[k]] % T;
                    key -= rem;
                    if (key < 0) {
                        key += T;
                    }
                    key /= cycles;
                    posInCycle[inds[k]] = (int) ((long) key * invMod(sum / cycles, cycleLen) % cycleLen);
                }
                ArraysUtils.randomShuffle(inds, i, j);
                for (int k = i; k < j; ++k) {
                    pInds[k] = inds[k];
                }
                Arrays.sort(pInds, i, j, (o1, o2) -> {
                    if (posInCycle[o1] != posInCycle[o2]) {
                        return Integer.compare(posInCycle[o1], posInCycle[o2]);
                    } else {
                        return Integer.compare(o1, o2);
                    }
                });
                for (int k = i; k < j; ++k) {
                    inds[k] = pInds[k];
                }
                int last = posInCycle[inds[i]];
                for (int k = j - 1; k >= i; --k) {
                    if (k == i || posInCycle[inds[k]] != posInCycle[inds[k - 1]]) {
                        ans[inds[k]] = (last - posInCycle[inds[k]] + cycleLen) % cycleLen;
                        if (ans[inds[k]] == 0) {
                            ans[inds[k]] = cycleLen;
                        }
                        last = posInCycle[inds[k]];
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    out.print(" ");
                }
                out.print(ans[i]);
            }
            out.println();
        }

        int gcd(int a, int b) {
            while (b != 0) {
                int c = a % b;
                a = b;
                b = c;
            }
            return a;
        }

        public static long[] euclid(long a, long b) {
            if (b == 0) {
                return new long[]{1, 0};
            } else {
                long[] res = euclid(b, a % b);
                long x = res[1];
                long y = res[0] - res[1] * (a / b);
                res[0] = x;
                res[1] = y;
                return res;
            }
        }

        int invMod(int x, int n) {
            if (gcd(x, n) != 1) {
                throw new RuntimeException();
            }
            long[] c = euclid(x, n);
            c[0] %= n;
            if (c[0] < 0) {
                c[0] += n;
            }
//        if (c[0] * x % n != 1) {
//            throw new RuntimeException();
//        }
            return (int) c[0];
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
        public static void randomShuffle(int[] A, int from, int to) {
            Random rnd = new Random();
            for (int i = from; i < to; ++i) {
                int pos = i + rnd.nextInt(to - i);
                swap(A, i, pos);
            }
        }

        public static void randomShuffle(int[] A) {
            randomShuffle(A, 0, A.length);
        }

        public static void swap(int[] A, int i, int j) {
            int aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }

    }
}