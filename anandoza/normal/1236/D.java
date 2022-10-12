import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        DAliceAndTheDoll solver = new DAliceAndTheDoll();
        solver.solve(1, in, out);
        out.close();
    }

    static class DAliceAndTheDoll {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int k = in.nextInt();

            TreeSet<Integer>[] rows = new TreeSet[n + 2];
            TreeSet<Integer>[] cols = new TreeSet[m + 2];
            for (int i = 0; i < rows.length; i++) {
                rows[i] = new TreeSet<>();
            }
            for (int i = 0; i < cols.length; i++) {
                cols[i] = new TreeSet<>();
            }

            for (int i = 0; i < n + 2; i++) {
                rows[i].add(0);
                rows[i].add(m + 1);
            }
            for (int i = 0; i < m + 2; i++) {
                cols[i].add(0);
                cols[i].add(n + 1);
            }


            for (int i = 0; i < k; i++) {
                int x = in.nextInt(), y = in.nextInt();
                rows[x].add(y);
                cols[y].add(x);
            }

            int x = 1, y = 1;
            int dir = 0;
            int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            long count = 0;
            int fail = 0;
            boolean first = true;

            TreeSet<Integer> globalRow = new TreeSet<>();
            globalRow.add(0);
            globalRow.add(m + 1);
            TreeSet<Integer> globalCol = new TreeSet<>();
            globalCol.add(0);
            globalCol.add(n + 1);

            while (true) {
                int dx = DIRS[dir][0], dy = DIRS[dir][1];
                if (dx == 0) {
                    int nextY;
                    if (dy > 0) {
                        nextY = rows[x].higher(y) - 1;
                        nextY = Math.min(nextY, globalRow.higher(y) - 1);
                    } else {
                        nextY = rows[x].lower(y) + 1;
                        nextY = Math.max(nextY, globalRow.lower(y) + 1);
                    }
                    if (nextY == y) {
                        fail++;
                    } else {
                        fail = 0;
                    }
                    globalCol.add(x);
                    count += Math.abs(nextY - y);
                    y = nextY;
                } else {
                    int nextX;
                    if (dx > 0) {
                        nextX = cols[y].higher(x) - 1;
                        nextX = Math.min(nextX, globalCol.higher(x) - 1);
                    } else {
                        nextX = cols[y].lower(x) + 1;
                        nextX = Math.max(nextX, globalCol.lower(x) + 1);
                    }
                    if (nextX == x) {
                        fail++;
                    } else {
                        fail = 0;
                    }
                    globalRow.add(y);
                    count += Math.abs(nextX - x);
                    x = nextX;
                }
                dir = (dir + 1) % 4;
                if (fail > 0 && !first)
                    break;
                first = false;
            }

            out.println(count + k + 1 == ((long) n) * m ? "Yes" : "No");
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