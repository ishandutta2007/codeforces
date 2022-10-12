import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        ETwoTypesOfSpells solver = new ETwoTypesOfSpells();
        solver.solve(1, in, out);
        out.close();
    }

    static class ETwoTypesOfSpells {
        TreeSet<Long> lower;
        TreeSet<Long> upper;
        long sumLower = 0;
        long sumUpper = 0;
        TreeSet<Long> lightning;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            lower = new TreeSet<>();
            upper = new TreeSet<>();
            lightning = new TreeSet<>();

            for (int i = 0; i < n; i++) {
                int t = in.nextInt();
                long d = in.nextLong();

                if (d < 0) {
                    remove(-d);
                } else {
                    add(d);
                    if (t == 1)
                        lightning.add(d);
                }

                balance();
                out.println(score());
            }
        }

        private void remove(long d) {
            if (lower.remove(d))
                sumLower -= d;
            if (upper.remove(d))
                sumUpper -= d;
            lightning.remove(d);
        }

        private void add(long d) {
            if (!lower.isEmpty() && d < lower.last()) {
                lower.add(d);
                sumLower += d;
            } else {
                upper.add(d);
                sumUpper += d;
            }
        }

        private void balance() {
            while (upper.size() > lightning.size())
                moveDown();
            while (upper.size() < lightning.size())
                moveUp();
        }

        private long score() {
            long r = sumUpper * 2 + sumLower;
            if (!lightning.isEmpty() && lightning.first() >= upper.first()) {
                r -= lightning.first();
                if (!lower.isEmpty())
                    r += lower.last();
            }
            return r;
        }

        private void moveDown() {
            long x = upper.pollFirst();
            lower.add(x);
            sumLower += x;
            sumUpper -= x;
        }

        private void moveUp() {
            long x = lower.pollLast();
            upper.add(x);
            sumUpper += x;
            sumLower -= x;
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

    }
}