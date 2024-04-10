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
        GSpecialPermutation solver = new GSpecialPermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class GSpecialPermutation {
        int[][] blocks = {null,
                          null,
                          null,
                          null,
                          {2, 4, 1, 3},
                          {2, 5, 3, 1, 4},
                          {2, 5, 3, 1, 4, 6},
                          {2, 5, 1, 3, 6, 4, 7}};

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            List<Integer> answer = new ArrayList<>();
            int last = 0;
            while (n >= 8) {
                add(answer, blocks[4], last);
                n -= 4;
                last += 4;
            }
            if (blocks[n] == null) {
                out.println(-1);
                return;
            }
            add(answer, blocks[n], last);
            out.println(Util.join(answer));
        }

        private void add(List<Integer> answer, int[] block, int last) {
            for (int i : block) {
                answer.add(i + last);

            }
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
}