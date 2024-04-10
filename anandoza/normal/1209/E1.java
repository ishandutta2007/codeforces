import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        E1RotateColumnsEasyVersion solver = new E1RotateColumnsEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1RotateColumnsEasyVersion {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solve(in, out);
            }
        }

        private void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[][] a = new int[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.readIntArray(m);
            }

            out.println(solve(n, m, a));
        }

        private int solve(int n, int m, int[][] a) {
            Cell[] cells = new Cell[n * m];
            for (int i = 0, index = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cells[index++] = new Cell(i, j, a[i][j]);
                    if (index == cells.length)
                        break;
                }
            }

            Arrays.sort(cells, Comparator.comparingInt(cell -> -cell.x));

            HashSet<Integer> colset = new HashSet<>();
            for (int i = 0; colset.size() < n && colset.size() < m; i++) {
                colset.add(cells[i].j);
            }

            ArrayList<Integer> cols = new ArrayList<>();
            cols.addAll(colset);

            int answer = 0;
            for (long perm = 0; perm < pow(n, cols.size() - 1); perm++) {
                long p = perm;
                int[] offset = new int[cols.size()];
                for (int col = 0; col < cols.size(); col++) {
                    offset[col] = (int) (p % n);
                    p /= n;
                }
                int sum = 0;
                for (int row = 0; row < n; row++) {
                    int max = 0;
                    for (int col = 0; col < cols.size(); col++) {
                        int cur = a[(row + offset[col]) % n][cols.get(col)];
                        max = Math.max(max, cur);
                    }
                    sum += max;
                }
                answer = Math.max(answer, sum);
            }

            return answer;
        }

        private long pow(int base, int exponent) {
            long p = 1;
            for (int i = 0; i < exponent; i++) {
                p *= base;
            }
            return p;
        }

        private class Cell {
            final int i;
            final int j;
            final int x;

            private Cell(int i, int j, int x) {
                this.i = i;
                this.j = j;
                this.x = x;
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