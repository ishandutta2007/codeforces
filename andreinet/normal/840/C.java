import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private static final int MOD = (int) 1e9 + 7;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            int[] primes = getPrimes(40_000);

            int[][] a = new int[n][];
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                IntList divs = new IntList();
                for (int j : primes) {
                    if (j * j > x) {
                        break;
                    }
                    int cnt = 0;
                    while (x % j == 0) {
                        cnt++;
                        x /= j;
                    }
                    if (cnt % 2 == 1) {
                        divs.add(j);
                    }
                }
                if (x > 1) {
                    divs.add(x);
                }
                a[i] = divs.toArray();
            }
            Comparator<int[]> cmp = ((o1, o2) -> {
                for (int i = 0; i < o1.length && i < o2.length; ++i) {
                    if (o1[i] < o2[i]) {
                        return -1;
                    } else if (o2[i] < o1[i]) {
                        return 1;
                    }
                }
                return Integer.compare(o1.length, o2.length);
            });
            Arrays.sort(a, cmp);
            IntList freqsList = new IntList();
            int cnt = 1;
            for (int i = 1; i < n; ++i) {
                if (cmp.compare(a[i], a[i - 1]) == 0) {
                    cnt++;
                } else {
                    freqsList.add(cnt);
                    cnt = 1;
                }
            }
            freqsList.add(cnt);
            int[][] comb = new int[2 * n + 1][2 * n + 1];
            for (int i = 0; i < comb.length; ++i) {
                comb[i][0] = 1;
                for (int j = 1; j <= i; ++j) {
                    comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
                }
            }
            int[] dp = new int[n];
            int[] ndp = new int[n];
            dp[0] = 1;
            int total = 0;
            int ans = 1;
            for (int x : freqsList.toArray()) {
                Arrays.fill(ndp, 0);
                for (int bad = 0; bad < n; ++bad) {
                    if (dp[bad] == 0) {
                        continue;
                    }
                    for (int putSeparately = 1; putSeparately <= x; ++putSeparately) {
                        for (int breakEq = 0; breakEq <= putSeparately; ++breakEq) {
                            int nState = bad + x - putSeparately - breakEq;
                            if (nState < 0 || nState >= n) {
                                continue;
                            }
                            int rem = total + 1 - bad;
                            int notBreak = putSeparately - breakEq;
                            if (breakEq > bad || notBreak > rem) {
                                continue;
                            }
                            int add = (int) ((long) comb[bad][breakEq] * comb[rem][notBreak] % MOD *
                                    comb[x - 1][putSeparately - 1] % MOD * dp[bad] % MOD);
                            ndp[nState] += add;
                            ndp[nState] %= MOD;
                        }
                    }
                }
                total += x;
                int[] aux = dp;
                dp = ndp;
                ndp = aux;
                ans = (int) ((long) ans * fact(x) % MOD);
            }
            ans = (int) ((long) ans * dp[0] % MOD);
            out.println(ans);
        }

        private int fact(int n) {
            int res = 1;
            for (int i = 2; i <= n; ++i) {
                res = (int) ((long) res * i % MOD);
            }
            return res;
        }

        private int[] getPrimes(int n) {
            boolean[] isPrime = new boolean[n + 1];
            Arrays.fill(isPrime, 2, isPrime.length, true);
            for (int i = 2; i * i <= n; ++i) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
            IntList primes = new IntList();
            for (int i = 2; i <= n; ++i) {
                if (isPrime[i]) {
                    primes.add(i);
                }
            }
            return primes.toArray();
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

    static interface IntIterator extends Iterator<Integer> {
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

        public int[] toArray() {
            return Arrays.copyOf(elem, size);
        }

        public int hashCode() {
            int hashCode = 0;
            for (int i = 0; i < size; ++i) {
                hashCode = 31 * hashCode + elem[i];
            }
            return hashCode;
        }

    }
}