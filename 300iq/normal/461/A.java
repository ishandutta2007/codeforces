/**
 * Created by ildar on 21.04.16.
 */
import java.io.*;
import java.util.*;

public class Main {

    String name = "ufo";

    void solve() throws IOException {
        int n = nextInt();
        int a[] = new int[n];
        long sum = 0;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            sum += a[i];
        }
        Arrays.sort(a);
        int l = 0;
        while (l < n) {
            ans += sum;
            if (l != n - 1) {
                ans += a[l];
            }
            sum -= a[l];
            l++;
        }
        out.println(ans);
    }

    void run() throws IOException {
        io();
        //file();
        solve();
        out.close();
    }
    public static void main(String [] args) throws IOException {
        new Main().run();
    }
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
    void io() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
    }
    void file() throws IOException {
        br = new BufferedReader(new FileReader(name + ".in"));
        out = new PrintWriter(new FileWriter(name + ".out"));
    }
    RuntimeException MyAssert(boolean x) {
        if (!x) {
            return new RuntimeException();
        }
        return null;
    }
    class Pair implements Comparable <Pair> {
        int a, b, ind;

        Pair() {

        }

        Pair(int x, int y, int i) {
            a = x;
            b = y;
            ind = i;
        }

        @Override
        public int compareTo(Pair o) {
            if (a != o.a) {
                return a - o.a;
            } else {
                return b - o.b;
            }
        }
    }
    double sqr(double x) {
        return x * x;
    }
}