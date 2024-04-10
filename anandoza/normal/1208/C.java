import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        CMagicGrid solver = new CMagicGrid();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMagicGrid {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int max = n * n;

            int[][] answer = new int[n][n];
            int row = 0, col = 0;
            for (int i = 0; i < max; i += 4) {
                answer[row][col] = i;
                answer[row][col + 1] = i + 1;
                answer[row + 1][col] = i + 2;
                answer[row + 1][col + 1] = i + 3;
                col += 2;
                if (col >= n) {
                    col = 0;
                    row += 2;
                }
            }

            for (int[] r : answer) {
                out.println(Util.join(r));
            }
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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