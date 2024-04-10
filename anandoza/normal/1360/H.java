import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        HBinaryMedian solver = new HBinaryMedian();
        solver.solve(1, in, out);
        out.close();
    }

    static class HBinaryMedian {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            long[] remove = new long[n];
            for (int i = 0; i < n; i++) {
                remove[i] = Long.parseLong(in.next(), 2);
            }
            long k = (1L << m) - n;
            long target = (k - 1) / 2;
            //System.out.println(Arrays.toString(remove));
            HashSet<Long> removed = new HashSet<>();
            for (long r : remove) {
                removed.add(r);
            }
            int less = 0;
            for (long r : remove) {
                if (r <= target)
                    less++;
            }
            //System.out.println("less: " + less);
            //System.out.println("init: " + target);
            for (int i = 0; i < less; i++) {
                target++;
                while (removed.contains(target))
                    target++;
            }
            //System.out.println("dbg " + target);
            String answer = Long.toBinaryString(target);
            while (answer.length() < m)
                answer = "0" + answer;
            out.println(answer);
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