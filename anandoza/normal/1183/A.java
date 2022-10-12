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
        ANearestInterestingNumber solver = new ANearestInterestingNumber();
        solver.solve(1, in, out);
        out.close();
    }

    static class ANearestInterestingNumber {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int a = in.nextInt();
            int answer = a;
            while (true) {
                if (sum(answer) % 4 == 0) {
                    break;
                }
                answer++;
            }

            out.println(answer);
        }

        int sum(int x) {
            int s = 0;
            for (char c : String.valueOf(x).toCharArray()) {
                s += c - '0';
            }
            return s;
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