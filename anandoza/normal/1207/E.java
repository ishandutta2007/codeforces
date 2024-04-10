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
        EXORGuessing solver = new EXORGuessing();
        solver.solve(1, in, out);
        out.close();
    }

    static class EXORGuessing {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("?");
            for (int i = 1; i <= 100; i++) {
                out.print(" " + (i));
            }
            out.println();
            out.flush();
            int a = in.nextInt();

            out.print("?");
            for (int i = 1; i <= 100; i++) {
                out.print(" " + (i << 7));
            }
            out.println();
            out.flush();
            int b = in.nextInt();

            int answer = (b & 127) | (a & (127 << 7));
            out.println("! " + answer);
            out.flush();
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

    }
}