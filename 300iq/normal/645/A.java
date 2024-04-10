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

    boolean used[][][][] = new boolean['Z' + 1]['Z' + 1]['Z' + 1]['Z' + 1];

    void rec(char a, char b, char c, char d) {
        used[a][b][c][d] = true;
        if (a == 'X') {
            if (!used[b][a][c][d])
                rec(b, a, c, d);
            if (!used[c][b][a][d])
                rec(c, b, a, d);
        }
        if (b == 'X') {
            if (!used[b][a][c][d])
                rec(b, a, c, d);
            if (!used[a][d][c][b])
                rec(a, d, c, b);
        }
        if (c == 'X') {
            if (!used[c][b][a][d])
                rec(c, b, a, d);
            if (!used[a][b][d][c])
                rec(a, b, d, c);
        }
        if (d == 'X') {
            if (!used[a][b][d][c])
                rec(a, b, d, c);
            if (!used[a][d][c][b])
                rec(a, d, c, b);
        }
    }

    private void solve() throws IOException {
        String s = next();
        char a = s.charAt(0);
        char b = s.charAt(1);
        s = next();
        char c = s.charAt(0);
        char d = s.charAt(1);
        s = next();
        char a1 = s.charAt(0);
        char b1 = s.charAt(1);
        s = next();
        char c1 = s.charAt(0);
        char d1 = s.charAt(1);
        rec(a, b, c, d);
        if (used[a1][b1][c1][d1])
            out.println("YES");
        else
            out.println("NO");
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