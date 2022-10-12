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
        LCrackingTheCode solver = new LCrackingTheCode();
        solver.solve(1, in, out);
        out.close();
    }

    static class LCrackingTheCode {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            char[] o = in.next().toCharArray();
            String s = "" + o[0] + o[2] + o[4] + o[3] + o[1];
            long n = Long.parseLong(s);
            long ans = 1;
            for (int i = 0; i < 5; i++) {
                ans *= n;
                ans %= 100_000;
            }
            String answer = String.valueOf(ans);
            while (answer.length() < 5)
                answer = "0" + answer;
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

    }
}