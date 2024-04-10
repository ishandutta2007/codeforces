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
        BNewYearAndAscentSequence solver = new BNewYearAndAscentSequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class BNewYearAndAscentSequence {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] s = new int[n][];
            int[] min = new int[n];
            int[] max = new int[n];
            boolean[] asc = new boolean[n];
            for (int i = 0; i < n; i++) {
                int l = in.nextInt();
                s[i] = in.readIntArray(l);
                min[i] = Util.min(s[i]);
                max[i] = Util.max(s[i]);
                for (int j = 0; j + 1 < l; j++) {
                    if (s[i][j] < s[i][j + 1]) {
                        asc[i] = true;
                        break;
                    }
                }
            }

            long answer = 0;
            long ascending = 0;
            int[] countMin = new int[1_000_001];
            int[] countMax = new int[1_000_001];
            long sumMax = 0, sumMin = 0;
            for (int i = 0; i < n; i++) {
                if (asc[i]) {
                    ascending++;
                    continue;
                }
                countMin[min[i]]++;
                countMax[max[i]]++;
                sumMax++;
            }

            for (int i = 0; i < countMin.length; i++) {
                sumMax -= countMax[i];
                answer += sumMin * sumMax;
                answer += countMin[i] * sumMax;
            }

            answer += ascending * ascending;
            answer += 2 * (ascending) * (n - ascending);

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

    static class Util {
        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

        public static int min(int... x) {
            int min = Integer.MAX_VALUE;
            for (int i : x) {
                min = Math.min(i, min);
            }
            return min;
        }

    }
}