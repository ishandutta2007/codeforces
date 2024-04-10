import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Deque;
import java.util.ArrayDeque;
import java.io.InputStreamReader;
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
        FBinaryStringReconstruction solver = new FBinaryStringReconstruction();
        solver.solve(1, in, out);
        out.close();
    }

    static class FBinaryStringReconstruction {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int z = in.nextInt(), m = in.nextInt(), o = in.nextInt();

            Deque<Integer> answer = new ArrayDeque<>();
            if (z > 0 || m > 0) {
                answer.add(0);
            } else {
                answer.add(1);
            }
            while (z > 0) {
                answer.addFirst(0);
                z--;
            }

            while (m > 0) {
                answer.addLast(1 - answer.peekLast());
                m--;
            }

            if (o == 0) {
                out.println(f(answer));
                return;
            }

            if (answer.peekLast() == 0) {
                answer.removeLast();
                answer.addFirst(1);
            }
            while (o > 0) {
                answer.addLast(1);
                o--;
            }

            out.println(f(answer));
        }

        private static String f(Deque<Integer> answer) {
            StringBuilder sb = new StringBuilder();
            for (int x : answer) {
                sb.append(x);
            }
            return sb.toString();
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