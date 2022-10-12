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
        DBicoloredRBS solver = new DBicoloredRBS();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBicoloredRBS {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();
            char[] chars = s.toCharArray();

            int[] parens = new int[n];
            for (int i = 0; i < n; i++) {
                if (chars[i] == '(') {
                    parens[i] = 1;
                } else {
                    parens[i] = -1;
                }
            }

            int depth = 0;
            int max = 0;
            for (int x : parens) {
                depth += x;
                max = Math.max(max, depth);
            }

            int ans = (max + 1) / 2;
            int[] answer = new int[n];

            depth = 0;
            for (int i = 0; i < n; i++) {
                if (Math.max(depth, depth + parens[i]) > ans) {
                    answer[i] = 1;
                }
                depth += parens[i];

            }

            StringBuilder sb = new StringBuilder();
            for (int x : answer) {
                sb.append(x);
            }

            out.println(sb);
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