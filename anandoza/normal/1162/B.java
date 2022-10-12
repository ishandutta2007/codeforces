import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BDoubleMatrix solver = new BDoubleMatrix();
        solver.solve(1, in, out);
        out.close();
    }

    static class BDoubleMatrix {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();

            int[][] a = new int[n + 1][m + 1];
            int[][] b = new int[n + 1][m + 1];


            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= m; j++)
                    a[i][j] = b[i][j] = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    a[i][j] = in.nextInt();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    b[i][j] = in.nextInt();

            int[][] x = new int[n + 1][m + 1];
            int[][] y = new int[n + 1][m + 1];

            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= m; j++) {
                    x[i][j] = Math.min(a[i][j], b[i][j]);
                    y[i][j] = Math.max(a[i][j], b[i][j]);
                }

            boolean answer = true;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    answer &= (x[i][j] < x[i + 1][j] && x[i][j] < x[i][j + 1]) && (y[i][j] < y[i + 1][j] && y[i][j] < y[i][j + 1]);
                }

            out.println(answer ? "Possible" : "Impossible");
        }

    }
}