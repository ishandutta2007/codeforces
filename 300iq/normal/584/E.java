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
        int pos[] = new int[n + 1];
        int a[] = new int[n + 1];
        int b[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = nextInt();
            pos[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            b[i] = nextInt();
            a[pos[b[i]]] = i;
        }
        int cost = 0;
        int head = 0;
        int pi[] = new int[10000000];
        int pj[] = new int[10000000];
        for (int i = 1; i <= n; i++) {
            int uk = i;
            while (uk <= n && a[uk] != i) uk++;
            for (int j = uk - 1; j >= i; j--)
                if (a[j] >= uk) {
                    cost += uk - j;
                    pi[head] = uk;
                    pj[head] = j;
                    ++head;
                    int t = a[uk];
                    a[uk] = a[j];
                    a[j] = t;
                    uk = j;
                }
        }
        out.println(cost);
        out.println(head);
        for (int i = 0; i < head; i++) {
            out.println(pi[i] + " " + pj[i]);
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}