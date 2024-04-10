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
        FTopforcesStrikesBack solver = new FTopforcesStrikesBack();
        solver.solve(1, in, out);
        out.close();
    }

    static class FTopforcesStrikesBack {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                long answer = solve(in, out);
                out.println(answer);
            }
        }

        private int solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Integer[] a = new Integer[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            Arrays.sort(a, Comparator.reverseOrder());

            if (n == 1) {
                return a[0];
            }
            if (n == 2) {
                if (a[0] % a[1] == 0)
                    return a[0];
                return a[0] + a[1];
            }

            int answer1 = a[0];

            int first = -1;
            for (int i = 0; i < n; i++) {
                if (a[0] % a[i] != 0) {
                    first = i;
                    answer1 += a[i];
                    break;
                }
            }
            if (first != -1)
                for (int i = first + 1; i < n; i++) {
                    if (a[0] % a[i] != 0 && a[first] % a[i] != 0) {
                        answer1 += a[i];
                        break;
                    }
                }

            int firstUnequal;
            for (firstUnequal = 0; firstUnequal < n; firstUnequal++) {
                if (!a[firstUnequal].equals(a[0]))
                    break;
            }

            int answer2 = 0;

            if (firstUnequal != n) {
                answer2 += a[firstUnequal];
                int first2 = -1;
                for (int i = firstUnequal + 1; i < n; i++) {
                    if (a[firstUnequal] % a[i] != 0) {
                        first2 = i;
                        answer2 += a[i];
                        break;
                    }
                }
                if (first2 != -1)
                    for (int i = first2 + 1; i < n; i++) {
                        if (a[firstUnequal] % a[i] != 0 && a[first2] % a[i] != 0) {
                            answer2 += a[i];
                            break;
                        }
                    }
            }

            return Math.max(answer1, answer2);
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