import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Comparator;
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
        DCandyBoxEasyVersion solver = new DCandyBoxEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class DCandyBoxEasyVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Integer[] typeCount = new Integer[n];
            Arrays.fill(typeCount, 0);
            for (int i = 0; i < n; i++) {
                typeCount[in.nextInt() - 1]++;
            }

            Arrays.sort(typeCount, Comparator.reverseOrder());

            long answer = 0;
            answer += typeCount[0];
            for (int i = 1; i < n; i++) {
                if (typeCount[i] >= typeCount[i - 1]) {
                    typeCount[i] = typeCount[i - 1] - 1;
                }
                if (typeCount[i] < 0)
                    break;
                answer += typeCount[i];
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}