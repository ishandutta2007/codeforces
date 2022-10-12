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
 *
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DPrimeGraph solver = new DPrimeGraph();
        solver.solve(1, in, out);
        out.close();
    }

    static class DPrimeGraph {
        List<String> edges = new ArrayList<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            final int MAX_EDGES = n * (n - 1) / 2;

            LinearSieve primes = new LinearSieve(MAX_EDGES);

            for (int i = 1; i + 1 <= n; i++) {
                connect(i, i + 1);
            }
            connect(n, 1);

            int index = 1;
            while (!primes.isPrime(edges.size())) {
                connect(index, index + 2);

                if (index % 2 == 1)
                    index++;
                else
                    index += 3;

                if (index + 2 > n) {
                    out.println(-1);
                    return;
                }
            }

            print(out);
        }

        private void print(PrintWriter out) {
            out.println(edges.size());
            for (String s : edges) {
                out.println(s);
            }
        }

        private void connect(int i, int j) {
            edges.add(i + " " + j);
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

    static class LinearSieve {
        public final BitSet isComposite;
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
            int size = 0;

            if (n <= 1) {
                isComposite = new BitSet();
            } else {
                isComposite = new BitSet(n);

                for (int i = 2; i <= n; i++) {
                    if (!isComposite.get(i)) {
                        if (size >= primes.length)
                            primes = resize(primes);
                        primes[size++] = i;
                    }

                    for (int j = 0; j < size; j++) {
                        int p = primes[j];
                        if (i * p > n)
                            break;
                        isComposite.set(i * p);
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

        public boolean isPrime(int p) {
            return !isComposite.get(p);
        }

    }
}