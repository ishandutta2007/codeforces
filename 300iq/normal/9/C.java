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
        int n = nextInt();
        long ans = 0;
        for (int i = 1; i < (1 << 10); i++) {
            if (Integer.parseInt(Integer.toBinaryString(i)) <= n)
                ans++;
        }
        out.println(ans);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}