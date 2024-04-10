//package com.company;

import java.io.*;
import java.util.*;
import java.math.*;

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

    int n, t[];

    void inc (int i, int delta) {
        for (; i < n; i = (i | (i + 1))) {
            t[i] += delta;
        }
    }

    int sum (int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }

    int sum (int l, int r) {
        return sum(r) - sum(l - 1);
    }

    private void solve() throws IOException {
        int n = nextInt(), m = nextInt();
        Set <Integer> s = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            for (int j = 0; j < x; j++) {
                s.add(nextInt());
            }
        }
        if (s.size() == m) {
            out.println("YES");
        }
        else {
            out.println("NO");
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