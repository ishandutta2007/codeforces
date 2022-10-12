import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.ArrayDeque;
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
        BAccurateLee solver = new BAccurateLee();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAccurateLee {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            char[] input = in.next().toCharArray();
            Deque<Integer> s = new ArrayDeque<>();
            for (char x : input)
                s.add(x - '0');

            Deque<Integer> left = new ArrayDeque<>();
            Deque<Integer> right = new ArrayDeque<>();
            while (!s.isEmpty() && s.peekFirst() == 0)
                left.addLast(s.pollFirst());
            while (!s.isEmpty() && s.peekLast() == 1)
                right.addFirst(s.pollLast());

            if (!s.isEmpty()) {
                left.addLast(0);
            }

            for (Queue<Integer> q : new Queue[]{left, right}) {
                while (!q.isEmpty()) {
                    out.print(q.poll());
                }
            }
            out.println();
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