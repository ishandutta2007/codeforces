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
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FLampsOnACircle solver = new FLampsOnACircle();
        solver.solve(1, in, out);
        out.close();
    }

    static class FLampsOnACircle {
        private InputReader in;
        private PrintWriter out;
        TreeSet<Integer> good;
        int n;
        int mod;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();

            int target = 0;
            for (int m = 2; m <= n; m++) {
                int cand = n - (m - 1) - ((n + m - 1) / m);
                if (cand > target) {
                    target = cand;
                    this.mod = m;
                }
            }
            if (target == 0) {
                out.println(0);
                out.flush();
                return;
            }

            good = new TreeSet<>();

            for (int i = 0; i < n; i++) {
                if (i % mod != 0)
                    good.add(i);
            }

            while (good.size() >= mod) {
                int[] move = new int[mod];
                for (int i = 0; i < mod; i++) {
                    move[i] = good.pollFirst();
                }

                play(move);
            }

            out.println(0);
            out.flush();
        }

        private void play(int... i) {
            out.print(i.length);
            for (int x : i) {
                out.print(" " + (x + 1));
            }
            out.println();
            out.flush();

            int opponent = in.nextInt() - 1;
            for (int j = 0; j < i.length; j++) {
                int move = (opponent + j) % n;
                if (move % mod != 0) {
                    good.add(move);
                }
            }
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