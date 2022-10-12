import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AnandOza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AFiveDimensionalPoints solver = new AFiveDimensionalPoints();
        solver.solve(1, in, out);
        out.close();
    }

    static class AFiveDimensionalPoints {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            if (n - 1 > 10) {
                out.println(0);
                return;
            }

            int[][] v = new int[n][];
            for (int i = 0; i < n; i++) {
                v[i] = in.readIntArray(5);
            }

            List<Integer> answer = new ArrayList<>();
            next:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (i == j || i == k || j == k)
                            continue;
                        int[] a = v[j].clone(), b = v[k].clone();
                        for (int l = 0; l < 5; l++) {
                            a[l] -= v[i][l];
                            b[l] -= v[i][l];
                        }
                        if (dot(a, b) > 0) {
                            continue next;
                        }
                    }
                }
                answer.add(i + 1);
            }

            out.println(answer.size());
            out.println(Util.join(answer));
        }

        private static int dot(int[] a, int[] b) {
            int answer = 0;
            for (int i = 0; i < a.length; i++) {
                answer += a[i] * b[i];
            }
            return answer;
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

        private Util() {
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