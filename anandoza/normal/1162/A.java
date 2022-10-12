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
        AZoningRestrictionsAgain solver = new AZoningRestrictionsAgain();
        solver.solve(1, in, out);
        out.close();
    }

    static class AZoningRestrictionsAgain {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), h = in.nextInt(), m = in.nextInt();

            int[] heights = new int[n];
            for (int i = 0; i < n; i++) {
                heights[i] = h;
            }

            for (int i = 0; i < m; i++) {
                int l = in.nextInt() - 1, r = in.nextInt() - 1, x = in.nextInt();
                for (int j = l; j <= r; j++) {
                    heights[j] = Math.min(heights[j], x);
                }
            }

            int answer = 0;
            for (int x : heights) {
                answer += x * x;
            }
            out.println(answer);
        }

    }
}