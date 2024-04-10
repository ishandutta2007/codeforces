import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
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
        EPolygon solver = new EPolygon();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPolygon {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            boolean[][] grid = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                char[] row = in.next().toCharArray();
                for (int j = 0; j < n; j++) {
                    grid[n - 1 - i][n - 1 - j] = row[j] == '1';
                }
            }

            Queue<Pii> q = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                q.add(Pii.of(i, -1));
            }
            for (int i = 0; i < n; i++) {
                q.add(Pii.of(-1, i));
            }
            int remaining = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j])
                        remaining++;
                }
            }
            while (!q.isEmpty()) {
                Pii cur = q.poll();
                if (cur.second >= 0 && cur.first + 1 < n && grid[cur.first + 1][cur.second]) {
                    q.add(Pii.of(cur.first + 1, cur.second));
                    grid[cur.first + 1][cur.second] = false;
                    remaining--;
                }
                if (cur.first >= 0 && cur.second + 1 < n && grid[cur.first][cur.second + 1]) {
                    q.add(Pii.of(cur.first, cur.second + 1));
                    grid[cur.first][cur.second + 1] = false;
                    remaining--;
                }
            }

            out.println(remaining == 0 ? "YES" : "NO");
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

    static class Pii {
        public final int first;
        public final int second;

        public Pii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public static Pii of(int first, int second) {
            return new Pii(first, second);
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;
            Pii pair = (Pii) o;
            return first == pair.first && second == pair.second;
        }

        public int hashCode() {
            return Arrays.hashCode(new int[]{first, second});
        }

        public String toString() {
            return "(" + first + ", " + second + ')';
        }

    }
}