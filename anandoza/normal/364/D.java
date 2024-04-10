import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
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
        DGhd solver = new DGhd();
        solver.solve(1, in, out);
        out.close();
    }

    static class DGhd {
        int n;
        long[] a;
        LinearSieve ls = new LinearSieve(1_000_000);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long start = System.nanoTime();
            long end = (long) (start + 3.8 * 1e9);
            n = in.nextInt();
            a = in.readLongArray(n);

            Counter<Long> all = new Counter<>();
            for (long x : a) {
                all.incr(x);
            }

            long answer = 1;
            HashSet<Long> seen = new HashSet<>();
            long mid = System.nanoTime();
            for (int iteration = 0; iteration < 100 && (iteration < 5 || mid + (System.nanoTime() - mid) * (1.0 + iteration) / iteration < end); iteration++) {
                if (seen.size() == all.distinct())
                    break;
                long x;
                do {
                    x = a[(int) (Math.random() * n)];
                } while (seen.contains(x));
                seen.add(x);

                Counter<Long> gcds = new Counter<>();
                for (long y : a)
                    gcds.incr(NumberTheory.gcd(x, y));
//            for (Map.Entry<Long, Integer> e : all.count.entrySet()) {
//                gcds.add(gcd(x, e.getKey()), e.getValue());
//            }

                long[] primes = getPrimes(x);

                long[] divisors = new long[6720];
                int divCount = 0;
                divisors[divCount++] = 1L;
                for (long p : primes) {
                    int before = divCount;
                    for (int i = 0; i < before; i++) {
                        long v = divisors[i];
                        for (long u = v; u <= x / p && x % (u * p) == 0; u *= p)
                            divisors[divCount++] = u * p;
                    }
                }

                long[] g = new long[divCount];
                System.arraycopy(divisors, 0, g, 0, divCount);

                Util.safeSort(g);
                Util.reverse(g);

                for (long p : primes) {
                    for (long v : g) {
                        if (v <= x / p) {
                            int c = gcds.get(v * p);
                            if (c > 0)
                                gcds.add(v, c);
                        }
                    }
                }
                for (long v : g) {
                    if (gcds.get(v) * 2 >= n)
                        answer = Math.max(answer, v);
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

    }

    static class NumberTheory {
        public static long gcd(long a, long b) {
            a = Math.abs(a);
            b = Math.abs(b);
            long c;
            while (a != 0) {
                c = a;
                a = b % a;
                b = c;
            }
            return b;
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

    static class Counter<T> {
        public final HashMap<T, Integer> count = new HashMap<>();

        public Counter() {
        }

        public Counter(T[] elements) {
            for (T t : elements)
                incr(t);
        }

        public Counter(Iterable<T> elements) {
            for (T t : elements)
                incr(t);
        }

        public void incr(T key) {
            count.merge(key, 1, Integer::sum);
        }

        public void add(T key, int add) {
            count.compute(key, (k, v) -> v == null ? add == 0 ? null : add : (v + add == 0 ? null : v + add));
        }

        public int get(T key) {
            return count.getOrDefault(key, 0);
        }

        public int distinct() {
            return count.size();
        }

    }

    static class Util {
        public static void safeSort(long[] x) {
            shuffle(x);
            Arrays.sort(x);
        }

        public static void shuffle(long[] x) {
            Random r = new Random();

            for (int i = 0; i <= x.length - 2; i++) {
                int j = i + r.nextInt(x.length - i);
                swap(x, i, j);
            }
        }

        public static void swap(long[] x, int i, int j) {
            long t = x[i];
            x[i] = x[j];
            x[j] = t;
        }

        public static void reverse(long[] x) {
            for (int i = 0, j = x.length - 1; i < j; i++, j--) {
                swap(x, i, j);
            }
        }

        private Util() {
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