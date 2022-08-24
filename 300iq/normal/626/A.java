import java.math.BigInteger;
import java.util.*;
import java.io.*;

import static java.lang.System.in;

public class Main {

    StringTokenizer st;
    BufferedReader br;
    PrintWriter out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }


    void solve() throws IOException {
        int n = nextInt();
        String s = next();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int x = 0;
                int y = 0;
                for (int t = i; t <= j; t++) {
                    if (s.charAt(t) == 'L') x--;
                    if (s.charAt(t) == 'R') x++;
                    if (s.charAt(t) == 'U') y++;
                    if (s.charAt(t) == 'D') y--;
                }
                if (x == 0 && y == 0)
                    ans++;
            }
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