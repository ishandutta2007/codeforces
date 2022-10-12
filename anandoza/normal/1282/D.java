import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Objects;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        DEnchantedArtifact solver = new DEnchantedArtifact();
        solver.solve(1, in, out);
        out.close();
    }

    static class DEnchantedArtifact {
        public static final char A = 'a';
        public static final char B = 'b';
        public static final int MAX = 300;
        InputReader in;
        PrintWriter out;
        HashMap<String, Integer> responses = new HashMap<>();
        boolean done = false;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            Pair<Integer, Integer> counts = findCounts();
            if (done)
                return;

            int a = counts.first, b = counts.second;
            int n = a + b;
            char[] guess = new char[n];
            Arrays.fill(guess, 'a');
            guess[0] = 'b';
            int[] res = new int[n];
            res[0] = guess(guess);
            char[] answer = new char[n];
            Arrays.fill(answer, 'x');
            for (int i = 1; i <= n - 2; i++) {
                guess[i] = 'b';
                res[i] = guess(guess);
                if (res[i] > res[i - 1])
                    answer[i] = A;
                else
                    answer[i] = B;
            }

            for (char x : answer) {
                if (x == A)
                    a--;
                if (x == B)
                    b--;
            }

            if (a == 2) {
                answer[0] = A;
                answer[n - 1] = A;
            } else if (b == 2) {
                answer[0] = B;
                answer[n - 1] = B;
            } else {
                int score = res[n - 2];
                for (int i = 1; i <= n - 2; i++) {
                    if (guess[i] != answer[i])
                        score--;
                }
                if (score > 0) {
                    answer[0] = guess[n - 1];
                    answer[n - 1] = guess[0];
                } else {
                    answer[0] = guess[0];
                    answer[n - 1] = guess[n - 1];
                }
            }

            guess(answer);
        }

        private Pair<Integer, Integer> findCounts() {
            char[] a = new char[MAX];
            Arrays.fill(a, A);
            char[] b = new char[MAX];
            Arrays.fill(b, B);
            int x = guess(a);
            int y = guess(b);
            if (done)
                return null;

            Pair<Integer, Integer> counts = Pair.of(MAX - x, MAX - y);
            if (counts.first == 0 || counts.second == 0) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < counts.first; i++)
                    sb.append(A);
                for (int i = 0; i < counts.second; i++)
                    sb.append(B);
                guess(sb.toString());
            }
            return counts;
        }

        private int guess(char[] b) {
            StringBuilder sb = new StringBuilder();
            for (char x : b)
                sb.append(x);
            return guess(sb.toString());
        }

        private int guess(String guess) {
            if (done)
                return -1;
            out.println(guess);
            out.flush();
            int result = in.nextInt();
            if (result == -1)
                System.exit(0);
            if (result == 0) {
                done = true;
            }
            responses.put(guess, result);
            return result;
        }

    }

    static class Pair<F, S> {
        public final F first;
        public final S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        public static <F, S> Pair<F, S> of(F first, S second) {
            return new Pair<>(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
        }

        public int hashCode() {
            return Objects.hash(first, second);
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
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