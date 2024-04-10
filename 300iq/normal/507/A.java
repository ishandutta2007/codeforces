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
        int n = nextInt(), k = nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int p[] = new int[n];
        int head = 0;
        for (int it = 0; it < n; it++) {
            int mini = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < a[mini]) {
                    mini = i;
                }
            }
            if (k >= a[mini]) {
                k -= a[mini];
                p[head] = mini + 1;
                head++;
                a[mini] = Integer.MAX_VALUE;
            }
        }
        out.println(head);
        for (int i = 0; i < head; i++) {
            out.print(p[i] + " ");
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