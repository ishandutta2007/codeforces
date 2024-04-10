//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int w = in.nextInt();

            int[] a = new int[n];
            int mn = Integer.MAX_VALUE;
            int mx = Integer.MIN_VALUE;
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
                if(i > 0) {
                    a[i] += a[i - 1];
                }

                mn = Math.min(mn, a[i]);
                mx = Math.max(mx, a[i]);
            }

            mn = Math.min(mn, 0);
            mx = Math.max(mx, 0);
            out.println(Math.max(0, w - (mx - mn) + 1));
        }
    }

    static class Pair<T, U> {
        T x;
        U y;

        Pair(T x, U y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}