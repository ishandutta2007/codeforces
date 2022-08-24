//package com.company;

import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);
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


    private void run() throws IOException {
        int n = nextInt(), k = nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        long s[] = new long[n];
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                s[i] = s[i - 1] + a[i];
            }
            else {
                s[i] = a[i];
            }
        }
        int ans = 0;
        int t = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = i, m, counter = -1;
            while (l <= r) {
                m = (l + r) / 2;
                long sum;
                if (m > 0)
                    sum = (i - m + 1L) * a[i] - (s[i] - s[m - 1]);
                else
                    sum = (i - m + 1L) * a[i] - s[i];
                if (sum <= k) {
                    r = m - 1;
                    counter = m;
                }
                else {
                    l = m + 1;
                }
            }
            if (counter == -1) {
                counter = 1;
            }
            else {
                counter = i - counter + 1;
            }
            if (counter > ans) {
                t = i;
                ans = counter;
            }
        }
        out.println(ans + " " + a[t]);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}