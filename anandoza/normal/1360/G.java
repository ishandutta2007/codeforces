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
        GABMatrix solver = new GABMatrix();
        solver.solve(1, in, out);
        out.close();
    }

    static class GABMatrix {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int a = in.nextInt(), b = in.nextInt();

            if (n * a != m * b) {
                out.println("NO");
                return;
            }

            char[][] answer = new char[n][m];
            for (int i = 0; i < n; i++) {
                Arrays.fill(answer[i], '0');
            }
            int count = 0, i = 0, j = 0;
            while (count < n * a) {
                if (answer[i][j] == '1') {
                    i++;
                }
                answer[i][j] = '1';
                i = (i + 1) % n;
                j = (j + 1) % m;
                count++;
            }
            out.println("YES");
            for (char[] r : answer) {
                out.println(String.valueOf(r));
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