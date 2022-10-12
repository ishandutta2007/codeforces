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
        BBeingawesomeism solver = new BBeingawesomeism();
        solver.solve(1, in, out);
        out.close();
    }

    static class BBeingawesomeism {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int r = in.nextInt(), c = in.nextInt();
            boolean[][] a = new boolean[r][c];
            for (int i = 0; i < r; i++) {
                char[] s = in.next().toCharArray();
                for (int j = 0; j < c; j++) {
                    a[i][j] = s[j] == 'A';
                }
            }

            int[] row = new int[r];
            int[] col = new int[c];
            int tot = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (a[i][j]) {
                        row[i]++;
                        col[j]++;
                        tot++;
                    }
                }
            }

            if (tot == 0) {
                out.println("MORTAL");
                return;
            }

            int answer = 4;
            if (tot == r * c)
                answer = Math.min(answer, 0);
            if (row[0] == c || row[r - 1] == c || col[0] == r || col[c - 1] == r)
                answer = Math.min(answer, 1);
            if (a[0][0] || a[r - 1][0] || a[r - 1][c - 1] || a[0][c - 1])
                answer = Math.min(answer, 2);
            if (row[0] > 0 || row[r - 1] > 0 || col[0] > 0 || col[c - 1] > 0)
                answer = Math.min(answer, 3);
            for (int i = 0; i < r; i++) {
                if (row[i] == c)
                    answer = Math.min(answer, 2);
            }
            for (int j = 0; j < c; j++) {
                if (col[j] == r)
                    answer = Math.min(answer, 2);
            }

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