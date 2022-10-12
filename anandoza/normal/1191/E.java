import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.BitSet;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        ETokitsukazeAndDuel solver = new ETokitsukazeAndDuel();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETokitsukazeAndDuel {
        int n;
        int k;
        BitSet ones = new BitSet();
        TreeSet<Integer> oneIndex = new TreeSet<>();
        TreeSet<Integer> zeroIndex = new TreeSet<>();
        int[] sum;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();

            String input = in.next();
            for (int i = 0; i < input.length(); i++) {
                ones.set(i, input.charAt(i) == '1');
            }
            sum = new int[n + 1];
            for (int i = 0; i < n; i++) {
                sum[i + 1] = sum[i];
                if (ones.get(i)) {
                    sum[i + 1]++;
                    oneIndex.add(i);
                } else {
                    zeroIndex.add(i);
                }
            }

            boolean first = doesFirstImmediatelyWin();
            boolean second = !first && doesSecondImmediatelyWin();

            if (first) {
                out.println("tokitsukaze");
            } else if (second) {
                out.println("quailty");
            } else {
                out.println("once again");
            }
        }

        private boolean doesFirstImmediatelyWin() {
            if (zeroIndex.isEmpty()) {
                return true;
            }
            if (oneIndex.isEmpty()) {
                return true;
            }
            int firstZero = zeroIndex.first(), lastZero = zeroIndex.last();
            int firstOne = oneIndex.first(), lastOne = oneIndex.last();

            if (lastOne - firstOne + 1 <= k)
                return true;
            if (lastZero - firstZero + 1 <= k)
                return true;

            return false;
        }

        private boolean doesSecondImmediatelyWin() {
            for (int i = 0; i + k <= n; i++) {
                // test making them all zeros
                int firstOne = oneIndex.first();
                if (firstOne >= i && firstOne < i + k) {
                    Integer test = oneIndex.higher(i + k - 1);
                    if (test == null) {
                        continue;
                    }
                    firstOne = test;
                }
                int lastOne = oneIndex.last();
                if (lastOne >= i && lastOne < i + k) {
                    Integer test = oneIndex.lower(i);
                    if (test == null) {
                        continue;
                    }
                    lastOne = test;
                }
                int firstZero = zeroIndex.first();
                firstZero = Math.min(firstZero, i);
                int lastZero = zeroIndex.last();
                lastZero = Math.max(lastZero, i + k - 1);

                if (lastZero - firstZero + 1 > k && lastOne - firstOne + 1 > k) {
                    return false;
                }
            }

            for (int i = 0; i + k <= n; i++) {
                // test making them all ones
                int firstZero = zeroIndex.first();
                if (firstZero >= i && firstZero < i + k) {
                    Integer test = zeroIndex.higher(i + k - 1);
                    if (test == null) {
                        continue;
                    }
                    firstZero = test;
                }
                int lastZero = zeroIndex.last();
                if (lastZero >= i && lastZero < i + k) {
                    Integer test = zeroIndex.lower(i);
                    if (test == null) {
                        continue;
                    }
                    lastZero = test;
                }
                int firstOne = oneIndex.first();
                firstOne = Math.min(firstOne, i);
                int lastOne = oneIndex.last();
                lastOne = Math.max(lastOne, i + k - 1);

                if (lastZero - firstZero + 1 > k && lastOne - firstOne + 1 > k) {
                    return false;
                }
            }

            return true;
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