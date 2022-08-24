import java.io.*;
import java.math.BigInteger;
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

    private void solve() throws IOException {
        int n = nextInt(), b = nextInt(), p = nextInt();
        int ans_1 = 0;
        int ans_2 = n * p;
        while (n > 1) {
            int k = 1;
            while (k * 2 <= n)
                k *= 2;
            ans_1 += k * b + (k / 2);
            n = k / 2 + (n - k);
        }
        out.println(ans_1 + " " + ans_2);
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