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
 * @author anand.oza
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BCatchOverflow solver = new BCatchOverflow();
        solver.solve(1, in, out);
        out.close();
    }

    static class BCatchOverflow {
        static final String ADD = "add";
        static final String END = "end";
        static final String OVERFLOW = "OVERFLOW!!!";
        static final long cap = (1L << 32) - 1;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();

            long currentValue = 0;
            long currentMultiplier = 1;
            int extraCount = 0;
            Deque<Long> multipliers = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                String s = in.next();
                if (s.equals(ADD)) {
                    currentValue += currentMultiplier;
                    if (currentValue > cap || extraCount > 0) {
                        out.println(OVERFLOW);
                        return;
                    }
                } else if (s.equals(END)) {
                    if (extraCount > 0) {
                        extraCount--;
                        multipliers.pollLast();
                    } else {
                        currentMultiplier /= multipliers.pollLast();
                    }
                } else {
                    long m = in.nextInt();
                    multipliers.addLast(m);
                    if (currentMultiplier > cap) {
                        extraCount++;
                    } else {
                        currentMultiplier *= m;
                    }
                }
            }

            out.println(currentValue);
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