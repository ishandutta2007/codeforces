import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        FIntegerGame solver = new FIntegerGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class FIntegerGame {
        private InputReader in;
        private PrintWriter out;
        long[] a;
        long[] s;
        boolean done = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            a = in.readLongArray(3);
            s = a.clone();
            Arrays.sort(s);

            out.println("First");
            out.flush();

            query(s[2]);
            while (!done()) {
                //System.out.println("a = " + Arrays.toString(a));
                if (!arith())
                    query(s[2] + (s[2] - s[0]) - s[1]);
                else
                    query(s[1] - s[0]);
            }
        }

        public boolean arith() {
            return s[2] - s[1] == s[1] - s[0];
        }

        public boolean done() {
            return done || s[0] == s[1] || s[1] == s[2];
        }

        public int query(long add) {
            out.println(add);
            out.flush();

            int index = in.nextInt() - 1;
            if (index == -1) {
                done = true;
                return index;
            }

            a[index] += add;
            s = a.clone();
            Arrays.sort(s);

            return index;
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

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}