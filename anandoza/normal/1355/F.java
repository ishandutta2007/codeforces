import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Objects;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.BitSet;
import java.util.ArrayDeque;
import java.util.function.ToLongFunction;
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
        FGuessDivisorsCount solver = new FGuessDivisorsCount();
        solver.solve(1, in, out);
        out.close();
    }

    static class FGuessDivisorsCount {
        InputReader in;
        PrintWriter out;
        LinearSieve ls = new LinearSieve(630);
        ArrayList<Long> initialQs;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            Queue<Integer> allPrimes = new ArrayDeque<>();
            for (int i : ls.primes) {
                allPrimes.add(i);
            }

            long prod = 1;
            initialQs = new ArrayList<>();
            while (!allPrimes.isEmpty()) {
                long p = allPrimes.poll();
                if (1_000_000_000_000_000_000L / p <= prod) {
                    initialQs.add(prod);
                    prod = 1;
                }
                prod *= p;
            }
            initialQs.add(prod);

            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve();
            }
        }

        private void answer(long answer) {
            answer = Math.max(2 * answer, 8);
            out.println("! " + answer);
            out.flush();
        }

        private long query(long q) {
            out.println("? " + q);
            out.flush();
            return in.nextLong();
        }

        private void solve() {

            ArrayList<Long> primes = new ArrayList<>();
            for (long q : initialQs) {
                long gcd = query(q);
                for (long p : ls.primes) {
                    if (gcd % p == 0) {
                        primes.add(p);
                    }
                }
            }

            long answer = 1;
            Queue<Pair<Long, Long>> queryPieces = new ArrayDeque<>();
            for (long p : primes) {
                long q = p;
                while (q < 1_000_000_000) {
                    q *= p;
                }
                q /= p;
                queryPieces.add(Pair.of(p, q));
            }

            while (!queryPieces.isEmpty()) {
                Pair<Long, Long> pair1 = queryPieces.poll();
                Pair<Long, Long> pair2 = null;
                long q = pair1.second;
                if (!queryPieces.isEmpty()) {
                    pair2 = queryPieces.poll();
                    q *= pair2.second;
                }

                final long gcd = query(q);

                ToLongFunction<Pair<Long, Long>> f = pair -> {
                    long g = NumberTheory.gcd(gcd, pair.second);
                    long count = 0;
                    while (g > 1) {
                        g /= pair.first;
                        count++;
                    }
                    return count + 1;
                };

                answer *= f.applyAsLong(pair1);
                if (pair2 != null)
                    answer *= f.applyAsLong(pair2);
            }

            answer(answer);
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

    static class InputReader {
        public BufferedReader reader;
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
}