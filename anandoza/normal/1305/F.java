import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.BitSet;
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
        FKuroniAndThePunishment solver = new FKuroniAndThePunishment();
        solver.solve(1, in, out);
        out.close();
    }

    static class FKuroniAndThePunishment {
        LinearSieve ls = new LinearSieve(1_000_000);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long[] a = in.readLongArray(n);
            int S = 3 * n;
            for (long x : a) {
                if (x == 1)
                    S--;
            }
            long[] b = new long[S];
            for (int i = 0; i < n; i++) {
                b[i] = a[i];
            }
            for (int i = 0; i < n; i++) {
                b[i + n] = a[i] + 1;
            }
            for (int i = 0, j = 0; i < n; i++) {
                if (a[i] == 1)
                    continue;
                b[j + 2 * n] = a[i] - 1;
                j++;
            }

            int answer = Integer.MAX_VALUE;
            for (int iteration = 0; iteration < 30; iteration++) {
                long x = b[(int) (Math.random() * b.length)];

                long[] primes = getPrimes(x);

                for (long p : primes) {
                    answer = Math.min(answer, score(p, a));
                }
            }

            out.println(answer);
        }

        private long[] getPrimes(long x) {
            List<Long> primes = new ArrayList<>();

            for (long p : ls.primes) {
                if (p * p > x)
                    break;
                if (x % p != 0)
                    continue;
                do {
                    x /= p;
                } while (x % p == 0);
                primes.add(p);
            }
            if (x > 1)
                primes.add(x);

            long[] array = new long[primes.size()];
            for (int i = 0; i < array.length; i++) {
                array[i] = primes.get(i);
            }
            return array;
        }

        private static int score(long p, long[] a) {
            long r = 0;
            for (long x : a) {
                if (x < p) {
                    r += p - x;
                    continue;
                }
                long d = x % p;
                r += Math.min(d, p - d);
                if (r > a.length)
                    return a.length;
            }
            return (int) r;
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }

    static class LinearSieve {
        public final BitSet isComposite;
        public final int[] leastPrimeDivisor;
        public final int[] primes;

        public LinearSieve(int n) {
            double estimate;
            if (n < 10000) {
                estimate = n + 1;
            } else {
                estimate = ((double) n) / Math.log(n);
                estimate *= 1.1;
            }
            int[] primes = new int[(int) estimate];
            leastPrimeDivisor = new int[n + 1];
            int size = 0;

            if (n <= 1) {
                isComposite = new BitSet();
            } else {
                isComposite = new BitSet(n + 1);

                for (int i = 2; i <= n; i++) {
                    if (!isComposite.get(i)) {
                        if (size >= primes.length)
                            primes = resize(primes);
                        primes[size++] = i;
                        leastPrimeDivisor[i] = i;
                    }

                    for (int j = 0; j < size; j++) {
                        int p = primes[j];
                        if (i * p > n)
                            break;
                        isComposite.set(i * p);
                        leastPrimeDivisor[i * p] = p;
                        if (i % p == 0)
                            break;
                    }
                }
            }

            this.primes = new int[size];
            System.arraycopy(primes, 0, this.primes, 0, size);
        }

        private static int[] resize(int[] primes) {
            int newSize = 1 + ((primes.length * 11) / 10);
            int[] newPrimes = new int[newSize];
            System.arraycopy(primes, 0, newPrimes, 0, primes.length);
            return newPrimes;
        }

    }
}