import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.AbstractCollection;
import java.util.PriorityQueue;
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
        BChessCheater solver = new BChessCheater();
        solver.solve(1, in, out);
        out.close();
    }

    static class BChessCheater {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            char[] input = in.next().toCharArray();
            boolean[] s = new boolean[n];
            for (int i = 0; i < n; i++) {
                s[i] = input[i] == 'W';
            }

            int loses = 0;
            for (int i = 0; i < n; i++) {
                if (!s[i])
                    loses++;
            }

            if (loses == n) {
                out.println(Math.max(0, 2 * k - 1));
                return;
            }

            PriorityQueue<Integer> chunks = new PriorityQueue<>();
            int extra = 0;

            for (int i = 0, j = 0; i < n; i = j) {
                while ((j < n) && (s[i] == s[j]))
                    j++;

                if (i != 0 && j != n && !s[i]) {
                    chunks.add(j - i);
                }
                if ((i == 0 || j == n) && !s[i]) {
                    extra += j - i;
                }
            }
            int score = 0;
            //System.out.println("s = " + Arrays.toString(s));
            for (int i = 0; i < n; i++) {
                if (s[i]) {
                    score++;
                    if (i > 0 && s[i - 1])
                        score++;
                }
            }
            //System.out.println("score = " + score);

            //System.out.println("chunks = " + chunks);
            while (k > 0 && !chunks.isEmpty()) {
                int cur = chunks.poll();
                if (k >= cur) {
                    score += cur * 2 + 1;
                    k -= cur;
                    continue;
                }
                int add = Math.min(k, cur);
                score += add * 2;
                k -= add;
            }
            //System.out.println("score after chunks = " + score);
            //System.out.println("extra = " + extra);

            if (k > 0) {
                score += 2 * Math.min(k, extra);
            }

            out.println(score);
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

    }
}