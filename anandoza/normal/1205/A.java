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
        AAlmostEqual solver = new AAlmostEqual();
        solver.solve(1, in, out);
        out.close();
    }

    static class AAlmostEqual {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            if (n % 2 == 0) {
                out.println("NO");
                return;
            }

            int[] answer = new int[2 * n];
            for (int i = 0; i < n; i++) {
                answer[2 * i] = 2 * i;
                answer[(2 * i + n) % (2 * n)] = 2 * i + 1;
            }

            for (int i = 0; i < answer.length; i++) {
                answer[i]++;
            }

            out.println("YES");
            out.println(Util.join(answer));
        }

    }

    static class Util {
        public static String join(int... i) {
            StringBuilder sb = new StringBuilder();
            for (int o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
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