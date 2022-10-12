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
        PAreaOfAStar solver = new PAreaOfAStar();
        solver.solve(1, in, out);
        out.close();
    }

    static class PAreaOfAStar {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            double n = in.nextLong();
            double r = in.nextLong();

            double theta = 2 * Math.PI / n;
            double d = Math.sin(theta / 2);
            double beta = Math.PI / n + Math.PI / n / 2;
            double H = Math.cos(theta / 2);
            double h = d / Math.tan(beta);

            double answer = d * H - d * h;
            answer *= n;
            answer *= r * r;

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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}