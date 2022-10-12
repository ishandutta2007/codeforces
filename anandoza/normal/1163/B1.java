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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        B1CatPartyEasyEdition solver = new B1CatPartyEasyEdition();
        solver.solve(1, in, out);
        out.close();
    }

    static class B1CatPartyEasyEdition {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] u = Permutations.readPermutation(in, n);
            int[] c = new int[10];

            int answer = 0;
            for (int i = 0; i < n; i++) {
                c[u[i]]++;
                int sum = 0;
                for (int j = 0; j < 10; j++) {
                    sum += c[j];
                }
                int k = 0, min = Integer.MAX_VALUE;
                for (int j = 0; j < 10; j++) {
                    if (c[j] == 0)
                        continue;
                    k++;
                    min = Math.min(min, c[j]);
                }
                if (sum == min * k + 1)
                    answer = i;
                int o = 0;
                HashSet<Integer> set = new HashSet<>();
                for (int j = 0; j < 10; j++) {
                    if (c[j] == 0)
                        continue;
                    if (c[j] == 1)
                        o++;
                    else
                        set.add(c[j]);
                }
                if (o == 1 && set.size() == 1)
                    answer = i;
                if (set.size() == 0)
                    answer = i;
                for (int j = 0; j < 10; j++) {
                    if (c[j] == 0)
                        continue;
                    set.add(c[j]);
                }
                if (k == 1)
                    answer = i;
            }

            out.println(answer + 1);
        }

    }

    static class Permutations {
        public static int[] readPermutation(InputReader in, int n) {
            int[] p = in.readIntArray(n);
            for (int i = 0; i < n; i++) {
                p[i]--;
            }
            return p;
        }

        private Permutations() {
        }

    }

    static class InputReader {
        public final BufferedReader reader;
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