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
        CVusTheCossackAndStrings solver = new CVusTheCossackAndStrings();
        solver.solve(1, in, out);
        out.close();
    }

    static class CVusTheCossackAndStrings {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] a = in.readBitString();
            int[] b = in.readBitString();

            int B = 0;
            for (int x : b)
                B ^= x;

            int n = a.length;
            int k = b.length;
            for (int i = 1; i < n; i++) {
                a[i] = a[i] ^ a[i - 1];
            }

            int answer = 0;
            if ((a[k - 1] ^ B) == 0) {
                answer++;
            }
            for (int i = 0; i + k < n; i++) {
                if ((a[i + k] ^ a[i] ^ B) == 0)
                    answer++;
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

        public int[] readBitString() {
            char[] chars = next().toCharArray();
            int[] x = new int[chars.length];
            for (int i = 0; i < x.length; i++) {
                x[i] = chars[i] - '0';
            }
            return x;
        }

    }
}