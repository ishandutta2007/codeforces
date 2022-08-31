import java.io.*;
import java.util.*;

public class Main {
    BufferedReader br;
    StringTokenizer st;
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

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    boolean vis(int n) {
        return (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0));
    }


    void solve() throws IOException {
        int y = nextInt();
        int d = 0;
        int p = -1;
        for (int i = 0; ; i++) {
            if (!vis(i)) {
                d += 365;
            } else {
                d += 366;
            }
            d %= 7;
            if (i == y) {
                p = d;
            } else if (i > y && p == d && vis(i) == vis(y)) {
                out.println(i);
                return;
            }
        }
    }

    void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}