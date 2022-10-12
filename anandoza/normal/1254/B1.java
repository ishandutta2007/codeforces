import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        B1SendBoxesToAliceEasyVersion solver = new B1SendBoxesToAliceEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class B1SendBoxesToAliceEasyVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            int total = 0;
            for (int x : a)
                total += x;

            HashSet<Integer> divisors = new HashSet<>();
            for (int i = 1; i * i <= total; i++) {
                if (total % i == 0) {
                    divisors.add(i);
                    divisors.add(total / i);
                }
            }
            divisors.remove(1);

            long answer = Long.MAX_VALUE;
            for (int k : divisors) {
                long score = 0;
                int start = -1, end = -1;
                for (int i = 0, count = 0; i < n; i++) {
                    count += a[i];
                    if (count == 1 && a[i] == 1)
                        start = i;
                    else if (count == k) {
                        end = i;
                        List<Integer> indices = new ArrayList<>();
                        for (int j = start; j <= end; j++) {
                            if (a[j] > 0)
                                indices.add(j);
                        }
                        for (int x = 0, y = indices.size() - 1; x < y; x++, y--) {
                            score += indices.get(y) - indices.get(x);
                        }
                        count = 0;
                    }
                }
                answer = Math.min(answer, score);
            }

            if (answer == Long.MAX_VALUE)
                answer = -1;
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}