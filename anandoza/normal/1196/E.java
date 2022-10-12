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
        EConnectedComponentOnAChessboard solver = new EConnectedComponentOnAChessboard();
        solver.solve(1, in, out);
        out.close();
    }

    static class EConnectedComponentOnAChessboard {
        StringBuilder sb;
        int countW;
        int countB;
        int w;
        int b;
        int flip;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            b = in.nextInt();
            w = in.nextInt();
            flip = 0;

            int row = 3;
            int col = 3;

            if (b < w) {
                int t = b;
                b = w;
                w = t;
                row++;
                flip = 1;
            }

            // now the first square (row, col) is "white" and w <= b

            sb = new StringBuilder();

            countW = 0;
            countB = 0;

            for (int i = 0; i < w; i++) {
                print(row, col + 2 * i);
                print(row, col + 2 * i + 1);
            }

            Util.ASSERT(countW == w);

            for (int i = 0; i < w; i++) {
                print(row - 1, col + 2 * i);
                print(row + 1, col + 2 * i);
            }
            print(row, col - 1);

            if (countB == b) {
                out.println("YES");
                sb.deleteCharAt(sb.length() - 1);
                out.println(sb);
            } else {
                out.println("NO");
            }
        }

        private void print(int i, int j) {
            if ((i + j + flip) % 2 == 0) {
                if (countW == w)
                    return;
                countW++;
            } else {
                if (countB == b)
                    return;
                countB++;
            }
            sb.append(i).append(" ").append(j).append("\n");
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

    static class Util {
        public static void ASSERT(boolean assertion) {
            if (!assertion)
                throw new AssertionError();
        }

    }
}