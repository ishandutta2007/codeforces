import java.util.*;
import java.io.*;
/**
 * Created by ildar on 18.03.16.
 */


public class Main {
    StringTokenizer st;
    BufferedReader br;
    PrintWriter out;
    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }


    private void solve() throws IOException {
        int n = nextInt(), k = nextInt();
        k = Math.min(k, n / 2);
        long res = 0;
        for (int i = 1; i <= k; i++) {
            res += (n - i);
        }
        for (int i = k + 1; i <= n; i++)
            res += Math.min(k, n - i);
        out.println(res);
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }
    public static void main(String [] args) throws IOException {
        new Main().run();
    }
}