import java.io.*;
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


    private void solve() throws IOException {
        int n = nextInt(), t = nextInt();
        String a = next(), b = next();
        int s = n - t;
        int fa, fb;
        char c[] = new char[n];
        for (int i = 0; i < n; i++) {
            c[i] = '#';
        }
        for (int i = 0; i < n; i++) {
            if (s == 0) break;
            if (a.charAt(i) == b.charAt(i)) {
                s--;
                c[i] = a.charAt(i);
            }
        }
        fa = fb = s;
        for (int i = 0; i < n; i++) {
            if (fa == 0) break;
            if (c[i] == '#') {
                c[i] = a.charAt(i);
                fa--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (fb == 0) break;
            if (c[i] == '#') {
                c[i] = b.charAt(i);
                fb--;
            }
        }
        if (fa != 0 || fb != 0) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (c[i] == '#') {
                for (int j = 'a'; j <= 'z'; j++) {
                    if (a.charAt(i) != j && b.charAt(i) != j) {
                        c[i] = (char) j;
                        break;
                    }
                }
            }
            out.print(c[i]);
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