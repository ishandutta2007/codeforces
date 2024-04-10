import java.util.*;
import java.io.*;

public class C {
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
        int k = nextInt();
        int[] a = new int[n];
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
            set.add(a[i]);
        }
        int q = nextInt();
        while (q-- > 0) {
            int x = nextInt();
            int res = 3311;
            for (int i = 0; i < n; i++) {
                for (int x1 = 0; x1 <= Math.min(k, x / a[i]); x1++) {
                    for (int x2 = 0; x2 <= k - x1; x2++) {
                        int curV = x - a[i] * x1;
                        if (curV == 0 && x2 == 0 || x2 != 0 && curV % x2 == 0 && set.contains(curV / x2)) {
                            res = Math.min(res, x1 + x2);
                        }
                    }
                }
            }
            out.println(res == 3311 ? "-1" : res);
        }
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
        new C().run();
    }
}