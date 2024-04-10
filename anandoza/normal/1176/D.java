import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.BitSet;
import java.util.Comparator;
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
        DRecoverIt solver = new DRecoverIt();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRecoverIt {
        Primes primes = new Primes(2750131);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            HashMap<Integer, Integer> counts = new HashMap<>();
            Integer[] a = new Integer[2 * n];
            for (int i = 0; i < 2 * n; i++) {
                a[i] = in.nextInt();
                counts.put(a[i], counts.getOrDefault(a[i], 0) + 1);
            }

            Arrays.sort(a, Comparator.reverseOrder());

            List<Integer> answer = new ArrayList<>();
            for (int x : a) {
                if (counts.get(x) == 0) {
                    continue;
                }

                if (primes.isPrime(x)) {
                    int other = Arrays.binarySearch(primes.primes, x) + 1;
                    answer.add(other);
                    counts.put(x, counts.get(x) - 1);
                    counts.put(other, counts.get(other) - 1);
                } else {
                    answer.add(x);
                    int other = getGreatestDivisor(x);
                    counts.put(x, counts.get(x) - 1);
                    counts.put(other, counts.get(other) - 1);
                }
            }

            StringBuilder sb = new StringBuilder();
            for (int x : answer) {
                sb.append(x + " ");
            }
            sb.deleteCharAt(sb.length() - 1);

            out.println(sb);
        }

        private static int getGreatestDivisor(int x) {
            for (int i = 2; ; i++) {
                if (x % i == 0) return x / i;
            }
        }

    }

    static class Primes {
        public final BitSet isPrime;
        public final int[] primes;

        public Primes(int N) {
            isPrime = new BitSet(N);
            isPrime.set(2, N + 1);
            for (int p = isPrime.nextSetBit(0); p <= Math.sqrt(N); p = isPrime.nextSetBit(p + 1)) {
                for (int composite = p * 2; composite <= N; composite += p) {
                    isPrime.clear(composite);
                }
            }

            primes = new int[isPrime.cardinality()];
            int p = isPrime.nextSetBit(0);
            for (int i = 0; i < primes.length; i++) {
                primes[i] = p;
                p = isPrime.nextSetBit(p + 1);
            }
        }

        public boolean isPrime(int p) {
            return isPrime.get(p);
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

    }
}