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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DTokitsukazeCSLAndStoneGame solver = new DTokitsukazeCSLAndStoneGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTokitsukazeCSLAndStoneGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Long[] a = new Long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
            }

            boolean answer = solveNew(a);

            out.println(answer ? "sjfnb" : "cslnb");
        }

        private static boolean solveNew(Long[] a) {
            int n = a.length;

            Arrays.sort(a);

            long moves = 0;
            boolean losesFirstMove = false;
            boolean twoFound = false;
            for (int i = 0; i < n; i++) {
                if (a[i] >= i) {
                    moves += a[i] - i;
                } else {
                    losesFirstMove = true;
                }
                if (i - 1 >= 0 && a[i - 1].equals(a[i])) {
                    if (twoFound)
                        losesFirstMove = true;
                    if (i - 2 >= 0 && a[i - 2].equals(a[i - 1] - 1))
                        losesFirstMove = true;
                    twoFound = true;
                }
            }

            return moves % 2 == 1 && !losesFirstMove;
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
}