import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
import java.util.BitSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BPowerProducts solver = new BPowerProducts();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPowerProducts {
        private static final int MAX = 100_000;
        private static final int SIG_LEN = 65;
        int n;
        int k;
        int[] a;
        LinearSieve primes = new LinearSieve(MAX);
        Map<Integer, Integer> primesIndex;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            a = in.readIntArray(n);

            if (k == 2) {
                out.println(solveKEquals2());
            } else {
                out.println(solveKGreaterThan2());
            }
        }

        private long solveKGreaterThan2() {
            Util.ASSERT(k > 2);

            primesIndex = new TreeMap<>();

            for (int i = 0; i < SIG_LEN; i++) {
                primesIndex.put(primes.primes[i], i);
            }

            HashMap<List<Integer>, Integer> count = new HashMap<>();
            for (int x : a) {
                List<Integer> key = makeSignature(x);
                if (key == null)
                    continue;
                count.merge(key, 1, Integer::sum);
            }

            long answer = 0;

            for (Entry<List<Integer>, Integer> entry : count.entrySet()) {
                List<Integer> signature = new ArrayList<>(SIG_LEN);
                for (int c : entry.getKey()) {
                    signature.add((k - c) % k);
                }
                if (signature.equals(entry.getKey())) {
                    answer += 2 * nc2(entry.getValue());
                } else {
                    answer += ((long) entry.getValue()) * count.getOrDefault(signature, 0);
                }
            }

            answer /= 2;

            return answer;
        }

        private List<Integer> makeSignature(int x) {
            int[] signature = new int[SIG_LEN];

            while (x > 1) {
                int p = primes.leastPrimeDivisor[x];

                if (!primesIndex.containsKey(p)) {
                    return null;
                }
                int i = primesIndex.get(p);
                signature[i]++;
                signature[i] %= k;
                x /= p;
            }

            List<Integer> result = new ArrayList<>(SIG_LEN);
            for (int c : signature) {
                result.add(c);
            }

            return result;
        }

        private long solveKEquals2() {
            Util.ASSERT(k == 2);

            HashMap<Integer, Integer> count = new HashMap<>();
            for (int i = 0; i < n; i++) {
                for (int p = 2; p * p <= a[i]; p++) {
                    while (a[i] % (p * p) == 0)
                        a[i] /= (p * p);
                }

                count.put(a[i], 1 + count.getOrDefault(a[i], 0));
            }

            long answer = 0;
            for (int x : count.values()) {
                answer += nc2(x);
            }

            return answer;
        }

        private static long nc2(long x) {
            return x * (x - 1) / 2;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
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