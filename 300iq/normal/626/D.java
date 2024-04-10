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
        int n = nextInt();
        int N = (int) 5e3 + 1;
        int cur = 0;
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        long cnt[] = new long[N];
        long pref[] = new long[N];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                cnt[a[i] - a[j]]++;
            }
        }
        pref[0] = cnt[0];
        for (int i = 1; i < N; i++) {
            pref[i] = pref[i - 1] + cnt[i];
        }
        long good = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (cnt[i] > 0 && cnt[j] > 0) {
                    long sum = cnt[i] * (long) cnt[j] * (long) pref[j - i - 1];
                    good += sum;
                }
            }
        }
        double b = (n * (long) (n - 1) / 2);
        b = b * b * b;
        out.println(good / b);
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