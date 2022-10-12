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
        BPlusFromPicture solver = new BPlusFromPicture();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPlusFromPicture {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            boolean answer = solve(in, out);

            out.println(answer ? "YES" : "NO");
        }

        public boolean solve(InputReader in, PrintWriter out) {
            int h = in.nextInt(), w = in.nextInt();

            boolean[][] picture = new boolean[h][w];
            for (int i = 0; i < h; i++) {
                char[] row = in.next().toCharArray();
                for (int j = 0; j < w; j++) {
                    picture[i][j] = (row[j] == '*');
                }
            }

            return solveFast(picture, h, w);
        }

        public boolean solveFast(boolean[][] picture, int h, int w) {
            int[] row = new int[h];
            for (int i = 0; i < h; i++) {
                row[i] = 0;
                for (int j = 0; j < w; j++)
                    row[i] += picture[i][j] ? 1 : 0;
            }
            int[] col = new int[w];
            for (int j = 0; j < w; j++) {
                col[j] = 0;
                for (int i = 0; i < h; i++) {
                    col[j] += picture[i][j] ? 1 : 0;
                }
            }

            int onlyRow = -1;
            for (int i = 0; i < h; i++) {
                if (row[i] > 1) {
                    if (onlyRow >= 0)
                        return false;
                    onlyRow = i;
                }
            }

            int onlyCol = -1;
            for (int j = 0; j < w; j++) {
                if (col[j] > 1) {
                    if (onlyCol >= 0)
                        return false;
                    onlyCol = j;
                }
            }

            if (onlyCol == -1 || onlyRow == -1)
                return false;

            TreeSet<Integer> indicesInRow = new TreeSet<>();
            for (int j = 0; j < w; j++) {
                if (picture[onlyRow][j]) {
                    indicesInRow.add(j);
                }
            }
            if ((indicesInRow.last() - indicesInRow.first() + 1) != indicesInRow.size())
                return false;
            TreeSet<Integer> indicesInCol = new TreeSet<>();
            for (int i = 0; i < h; i++) {
                if (picture[i][onlyCol]) {
                    indicesInCol.add(i);
                }
            }
            if ((indicesInCol.last() - indicesInCol.first() + 1) != indicesInCol.size())
                return false;

            if (indicesInRow.last() == onlyCol || indicesInRow.first() == onlyCol)
                return false;
            if (indicesInCol.last() == onlyRow || indicesInCol.first() == onlyRow)
                return false;

            int totalCount = 0;
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    totalCount += picture[i][j] ? 1 : 0;

            if (totalCount != indicesInCol.size() + indicesInRow.size() - 1)
                return false;

            return indicesInCol.contains(onlyRow) && indicesInRow.contains(onlyCol);
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