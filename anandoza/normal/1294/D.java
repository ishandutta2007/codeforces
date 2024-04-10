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
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DMEXMaximizing solver = new DMEXMaximizing();
        solver.solve(1, in, out);
        out.close();
    }

    static class DMEXMaximizing {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt(), x = in.nextInt();

            int answer = 0;
            boolean[] present = new boolean[q + 1];

            int[] next = new int[x];
            for (int i = 0; i < q; i++) {
                int y = in.nextInt();
                int bucket = y % x;
                int val = bucket + next[bucket] * x;
                if (val < present.length) {
                    present[val] = true;
                    next[bucket]++;
                }

                while (present[answer])
                    answer++;

                out.println(answer);
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