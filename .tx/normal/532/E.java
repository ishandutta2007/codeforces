/**
 * Created by  on 17.04.2015.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class E {
    BufferedReader br;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    char nextChar() throws IOException {
        return (char) (br.read());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }


    private void solve() throws IOException {
        int n = nextInt();
        String s = nextLine();
        String s1 = nextLine();
        char[] c = s.toCharArray();
        char[] c1 = s1.toCharArray();
        int j = 0;
        boolean f = false;
        int l = 0, r = n - 1;
        while (l < n && c[l] == c1[l]) {
            l++;
        }
        while (r >= 0 && c[r] == c1[r]) {
            r--;
        }

        if (l == r) {
            out.println(2);
            return;
        }
        f = true;
        for (int i = l; i < r; i++) {
            if (c[i] != c1[i+1]) {
                f = false;
            }
        }
        boolean f1 = true;
        for (int i = l; i < r; i++) {
            if (c1[i] != c[i+1]) {
                f1 = false;
            }
        }
        if (f1 && f) {
            out.println(2);
            return;
        }
        if (f || f1) {
            out.println(1);
            return;
        }
        out.print(0);

    }



    void run() throws IOException {
        //br = new BufferedReader(new FileReader("input.txt"));
        //out = new PrintWriter("output.txt");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        // Locale.setDefault(Locale.US);
        new E().run();
    }
}