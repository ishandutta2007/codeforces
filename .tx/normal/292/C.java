import java.io.*;
import java.util.*;

public class TaskC implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(in.readLine());
            }
            return stok.nextToken();
        } catch (IOException e) {
            return null;
        }
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }


    // File names!!!

    int n;
    int[] a = new int[10];
    int[] b = new int[12];
    int[] c = new int[12];
    boolean[] f = new boolean[10];

    int check(int i, int len) {
        if (len > 1 && c[i] == 0) {
            return -1;
        }
        int res = 0;
        for (int j = 0; j < len; j++) {
            res = res * 10 + c[i + j];
        }
        if (res < 0 || res > 255) {
            return -1;
        }
        return res;
    }

    void go(int l2, boolean even) {
        int len = l2 * 2 + (even ? 0 : 1);
        if (even) {
            for (int i = l2; i < len; i++) {
                b[i] = b[len - i - 1];
            }
        } else {
            for (int i = l2 + 1; i < len; i++) {
                b[i] = b[len - i - 1];
            }
        }

        Arrays.fill(f, false);
        for (int i = 0; i < len; i++) {
            c[i] = a[b[i]];
            f[b[i]] = true;
        }

        for (int i = 0; i < n; i++) {
            if (!f[i]) {
                return;
            }
        }

        int c1, c2, c3, c4;
        for (int i1 = 1; i1 <= 3; i1++) {
            c1 = check(0, i1);
            if (c1 == -1) continue;

            for (int i2 = 1; i2 <= 3; i2++) {
                if (i1 + i2 >= len) continue;

                c2 = check(i1, i2);
                if (c2 == -1) continue;
                for (int i3 = 1; i3 <= 3; i3++) {
                    if (i1 + i2 + i3 >= len) {
                        break;
                    }

                    c3 = check(i1 + i2, i3);
                    if (c3 == -1) continue;

                    int i4 = len - i1 - i2 - i3;
                    c4 = check(i1 + i2 + i3, i4);
                    if (c4 == -1) continue;
                    ans.add(String.format("%d.%d.%d.%d", c1, c2, c3, c4));
                }
            }
        }
    }

    ArrayList<String> ans = new ArrayList<String>();

    void solve() throws IOException {
        n = nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }


        for (int len = 4; len <= 12; len++) {
            int l2 = len / 2;
            int sc = (int) Math.pow(n, l2);
            Arrays.fill(b, 0);

            for (int i = 0; i < sc; i++) {
                for (int j = l2 - 1; j > 0 && b[j] >= n; j--) {
                    b[j] -= n;
                    b[j - 1]++;
                }
                if (len % 2 == 0) {
                    go(l2, true);
                } else {
                    for (int j = 0; j < n; j++) {
                        b[l2] = j;
                        go(l2, false);
                    }
                }
                b[l2 - 1]++;
            }
        }

        out.println(ans.size());
        for (String i : ans) {
            out.println(i);
        }
    }

    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();
            out.close();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new Thread(new TaskC()).start();
    }
}//rzlrmd