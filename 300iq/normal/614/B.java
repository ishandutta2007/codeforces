import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String s = br.readLine();
            st = new StringTokenizer(s);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws  IOException {
        return Double.parseDouble(next());
    }

    void myAssert(boolean statement) {
        if (!statement) {
            throw new RuntimeException();
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        String bad = "1";
        int zeros = 0;
        String s;
        for (int i = 0; i < n; i++) {
            s = next();
            int t = 0;
            int k = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    t++;
                }
                if (s.charAt(j) != '1' && s.charAt(j) != '0') {
                    k = 1;
                }
            }
            if (t > 1 || k != 0) {
                bad = s;
            }
            else if (!s.equals("1") && !s.equals("0")) {
                zeros += s.length() - 1;
            }
            if (s.equals("0")) {
                out.println(0);
                return;
            }
        }
        out.print(bad);
        for (int i = 0; i < zeros; i++) {
            out.print(0);
        }
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