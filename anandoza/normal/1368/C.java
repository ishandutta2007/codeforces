import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        CEvenPicture solver = new CEvenPicture();
        solver.solve(1, in, out);
        out.close();
    }

    static class CEvenPicture {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            n += 2;

            List<Pii> answer = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                answer.add(Pii.of(i, i));
            }
            for (int i = 0; i < n - 1; i++) {
                answer.add(Pii.of(i + 1, i));
                answer.add(Pii.of(i, i + 1));
            }

            //char[][] grid = new char[100][100];
            //for (int i = 0; i < grid.length; i++) {
            //    for (int j = 0; j < grid.length; j++) {
            //        grid[i][j] = ' ';
            //    }
            //}
            //for (Pii p : answer) {
            //    grid[p.first][p.second] = 'X';
            //}
            //for (char[] row : grid) {
            //    System.out.println(String.valueOf(row));
            //}

            out.println(answer.size());
            for (Pii p : answer) {
                out.println(p.first + " " + p.second);
            }
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