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
import java.util.Collections;
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
        E1ReadingBooksEasyVersion solver = new E1ReadingBooksEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1ReadingBooksEasyVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            List<Integer> both = new ArrayList<>();
            List<Integer> alice = new ArrayList<>();
            List<Integer> bob = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int t = in.nextInt();
                int a = in.nextInt();
                int b = in.nextInt();
                if (a == 1 && b == 1) {
                    both.add(t);
                } else if (a == 1) {
                    alice.add(t);
                } else if (b == 1) {
                    bob.add(t);
                }
            }
            Collections.sort(alice);
            Collections.sort(bob);
            for (int i = 0; i < Math.min(alice.size(), bob.size()); i++) {
                both.add(alice.get(i) + bob.get(i));
            }
            Collections.sort(both);

            if (both.size() < k) {
                out.println(-1);
                return;
            }

            long answer = 0;
            for (int i = 0; i < k; i++) {
                answer += both.get(i);
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