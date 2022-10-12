import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.ArrayDeque;
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
        DChristmasTrees solver = new DChristmasTrees();
        solver.solve(1, in, out);
        out.close();
    }

    static class DChristmasTrees {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            long[] x = in.readLongArray(n);

            HashSet<Long> visited = new HashSet<>();
            for (long i : x)
                visited.add(i);

            HashMap<Long, Integer> dist = new HashMap<>();
            Queue<Long> q = new ArrayDeque<>();
            for (long i : x) {
                for (long j = i - 1; j <= i + 1; j += 2) {
                    if (visited.contains(j))
                        continue;
                    visited.add(j);
                    dist.put(j, 1);
                    q.add(j);
                }
            }
            List<Long> answer = new ArrayList<>();
            long score = 0;
            for (int iter = 0; iter < m; iter++) {
                long i = q.poll();
                answer.add(i);
                score += dist.get(i);
                for (long j = i - 1; j <= i + 1; j += 2) {
                    if (visited.contains(j))
                        continue;
                    visited.add(j);
                    dist.put(j, dist.get(i) + 1);
                    q.add(j);
                }
            }

            out.println(score);
            out.println(Util.join(answer));
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
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

        private Util() {
        }

    }
}