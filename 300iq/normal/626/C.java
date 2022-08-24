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
        int n = nextInt(), m = nextInt();
        int l = 1, r = (int) 1e9;
        while (l < r - 1) {
            int mb = (l + r) / 2;
            int A = mb / 2;
            int B = mb / 3;
            int C = mb / 6;
            A -= C;
            B -= C;
            int lA = Math.max(0, n - A);
            int lB = Math.max(0, m - B);
            if (lA + lB <= C) r = mb;
            else l = mb;
        }
        out.println(r);
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