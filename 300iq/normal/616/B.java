import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;

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
        int ans = 0;
        int min = Integer.MAX_VALUE;
        int n = nextInt();
        int m = nextInt();
        for (int i = 0; i < n; i++) {
            min = Integer.MAX_VALUE;
            for (int j = 0; j < m; j++) {
                min = Math.min(min, nextInt());
            }
            ans = Math.max(ans, min);
        }
        out.println(ans);
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
	    new Main().run();
    }
}