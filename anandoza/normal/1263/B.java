import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
        BPINCodes solver = new BPINCodes();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPINCodes {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[][] codes = new char[n][];
            for (int i = 0; i < n; i++) {
                codes[i] = in.next().toCharArray();
            }

            int[] lastDigits = new int[n];
            for (int i = 0; i < n; i++) {
                lastDigits[i] = codes[i][0] - '0';
            }

            int answer = 0;
            for (int i = 0; i < n; i++) {
                HashSet<Character> invalid = new HashSet<>();
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        continue;
                    if (String.valueOf(codes[i]).substring(1).equals(String.valueOf(codes[j]).substring(1))) {
                        invalid.add(codes[j][0]);
                    }
                }
                if (invalid.contains(codes[i][0])) {
                    answer++;
                    for (char x = '0'; x <= '9'; x++) {
                        if (!invalid.contains(x)) {
                            codes[i][0] = x;
                            break;
                        }
                    }
                }
            }

            out.println(answer);
            for (char[] x : codes)
                out.println(String.valueOf(x));
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