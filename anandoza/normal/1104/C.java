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
        CGridGame solver = new CGridGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class CGridGame {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int n = s.length();

            boolean[] vertical = new boolean[n];
            for (int i = 0; i < n; i++) {
                vertical[i] = s.charAt(i) == '0';
            }

            int v = 0;
            int h = 0;
            for (boolean isVertical : vertical) {
                if (isVertical) {
                    v++;
                    switch (v) {
                        case 1:
                            out.println("1 1");
                            break;
                        case 2:
                            out.println("1 2");
                            break;
                        case 3:
                            out.println("1 3");
                            break;
                        case 4:
                            out.println("1 4");
                            v = 0;
                            break;
                    }
                } else {
                    h++;
                    switch (h) {
                        case 1:
                            out.println("3 1");
                            break;
                        case 2:
                            out.println("3 3");
                            h = 0;
                            break;
                    }
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

    }
}