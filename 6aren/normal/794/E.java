import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author 6aren
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        int N = 300005;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[N];
            int[] b = new int[N];
            int[] c = new int[N];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 1; i < n; i++) {
                b[i] = Math.max(a[i], a[i + 1]);
                c[i] = Math.min(a[i], a[i + 1]);
            }
            int max1 = 0;
            if (n % 2 == 0) max1 = Math.min(a[n / 2], a[n / 2 + 1]);
            int max2 = 0;
            for (int k = 0; k < n - 1; k++) {
                if ((n - k) % 2 == 0) {
                    int u = (1 + n - k) / 2;
                    int v = (k + 1 + n) / 2;
                    max2 = Math.max(max2, Math.max(b[u], b[v]));
                    out.print(max2);
                    out.print(' ');
                } else {
                    int u = (1 + n - k) / 2 - 1;
                    int v = (k + 1 + n) / 2;
                    max1 = Math.max(max1, Math.max(c[u], c[v]));
                    out.print(max1);
                    out.print(' ');
                }
            }
            int maxi = 0;
            for (int i = 1; i <= n; i++) {
                maxi = Math.max(maxi, a[i]);
            }
            out.print(maxi);
        }

    }
}