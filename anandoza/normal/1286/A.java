import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        AGarland solver = new AGarland();
        solver.solve(1, in, out);
        out.close();
    }

    static class AGarland {
        int n;
        int[] p;
        HashMap<AGarland.State, Integer> cache = new HashMap<>();

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            p = in.readIntArray(n);

            int odd = (n + 1) / 2;
            int even = n / 2;
            for (int i = 0; i < n; i++) {
                if (p[i] == 0)
                    continue;
                if (p[i] % 2 == 1)
                    odd--;
                else
                    even--;
            }

            int answer = f(0, -1, even, odd);

            out.println(answer);
        }

        private int f(int index, int lastParity, int even, int odd) {
            AGarland.State s = new AGarland.State(index, lastParity, even, odd);
            if (!cache.containsKey(s)) {
                int result = Integer.MAX_VALUE;
                if (index == n)
                    return 0;
                if (p[index] != 0) {
                    result = f(index + 1, 2 - (p[index] % 2), even, odd);
                    if (lastParity > 0 && lastParity != 2 - (p[index] % 2))
                        result++;
                } else {
                    if (even > 0) {
                        int sub = f(index + 1, 2, even - 1, odd);
                        if (lastParity == 1)
                            sub++;
                        result = Math.min(result, sub);
                    }
                    if (odd > 0) {
                        int sub = f(index + 1, 1, even, odd - 1);
                        if (lastParity == 2)
                            sub++;
                        result = Math.min(result, sub);
                    }
                }
                cache.put(s, result);
            }
            return cache.get(s);
        }

        private static class State {
            final int index;
            final int lastParity;
            final int even;
            final int odd;

            private State(int index, int lastParity, int even, int odd) {
                this.index = index;
                this.lastParity = lastParity;
                this.even = even;
                this.odd = odd;
            }

            public boolean equals(Object o) {
                if (this == o)
                    return true;
                if (o == null || getClass() != o.getClass())
                    return false;
                AGarland.State state = (AGarland.State) o;
                return index == state.index && lastParity == state.lastParity && even == state.even && odd == state.odd;
            }

            public int hashCode() {
                return Objects.hash(index, lastParity, even, odd);
            }

            public String toString() {
                return "State{" + "index=" + index + ", lastParity=" + lastParity + ", even=" + even + ", odd=" + odd + '}';
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

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}