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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AAhahahahahahahaha solver = new AAhahahahahahahaha();
        solver.solve(1, in, out);
        out.close();
    }

    static class AAhahahahahahahaha {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] c = new int[2];
            for (int x : a)
                c[x]++;
            int answer = c[0] >= c[1] ? 0 : 1;
            int count = c[answer];
            if (count % 2 == 1 && answer == 1)
                count--;
            out.println(count);
            for (int i = 0; i < count; i++) {
                out.print(answer + " ");
            }
            out.println();
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}