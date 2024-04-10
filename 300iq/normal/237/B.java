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
        int c[] = new int[n];
        int a[][] = new int[57][57];
        int ti[] = new int[57 * 57];
        int tj[] = new int[57 * 57];

        int x[] = new int[57 * 57], y[] = new int[57 * 57], p[] = new int[57 * 57], q[] = new int[57 * 57];

        for (int i = 0; i < n; i++) {
            c[i] = nextInt();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c[i]; j++) {
                a[i][j] = nextInt();
                ti[a[i][j]] = i;
                tj[a[i][j]] = j;
            }
        }
        int counter = 0;
        int head = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c[i]; j++) {
                counter++;
                if (a[i][j] != counter) {
                    x[head] = i + 1;
                    y[head] = j + 1;
                    p[head] = ti[counter] + 1;
                    q[head] = tj[counter] + 1;
                    head++;
                    int t = a[i][j];
                    a[i][j] = a[ti[counter]][tj[counter]];
                    a[ti[counter]][tj[counter]] = t;
                    ti[t] = ti[counter];
                    tj[t] = tj[counter];
                    ti[counter] = i;
                    tj[counter] = j;
                }
            }
        }
        out.println(head);
        for (int i = 0; i < head; i++) {
            out.println(x[i] + " " + y[i] + " " + p[i] + " " + q[i]);
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}