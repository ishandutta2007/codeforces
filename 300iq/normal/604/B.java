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
        int n = nextInt(), k = nextInt(), ans = 0;
        int s[] = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = nextInt();
            ans = Math.max(ans, s[i]);
        }
        for (int i = 0; i < n - k; i++) {
            ans = Math.max(ans, s[i] + s[(n - (2 * k - n)) - 1 - i]);
        }
        out.println(ans);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}