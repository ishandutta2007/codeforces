import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
        FConsecutiveSubsequence solver = new FConsecutiveSubsequence();
        solver.solve(1, in, out);
        out.close();
    }

    static class FConsecutiveSubsequence {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);

            HashMap<Integer, Integer> index = new HashMap<>();
            int[] prev = new int[n];
            int[] ans = new int[n];

            for (int i = 0; i < n; i++) {
                prev[i] = -1;
                ans[i] = 1;

                if (index.containsKey(a[i] - 1)) {
                    Integer prevIndex = index.get(a[i] - 1);
                    ans[i] = ans[prevIndex] + 1;
                    prev[i] = prevIndex;
                }
                if (!index.containsKey(a[i]) || ans[i] > ans[index.get(a[i])]) {
                    index.put(a[i], i);
                }
            }

            int maxIndex = -1, max = 0;
            for (int i = 0; i < n; i++) {
                if (ans[i] > max) {
                    max = ans[i];
                    maxIndex = i;
                }
            }

            ArrayDeque<Integer> seq = new ArrayDeque<>();
            while (maxIndex >= 0) {
                seq.addFirst(maxIndex + 1);
                maxIndex = prev[maxIndex];
            }

            out.println(Util.max(ans));
            out.println(Util.join(seq));
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
        public static String join(Iterable i) {
            StringBuilder sb = new StringBuilder();
            for (Object o : i) {
                sb.append(o);
                sb.append(" ");
            }
            if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
            return sb.toString();
        }

        public static int max(int... x) {
            int max = Integer.MIN_VALUE;
            for (int i : x) {
                max = Math.max(i, max);
            }
            return max;
        }

    }
}