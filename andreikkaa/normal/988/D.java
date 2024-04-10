//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();

            Integer[] a = new Integer[n];
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);

            for(int p = 1; p != (1 << 30); p <<= 1) {
                int j = 0;
                int k = 0;
                for (int i = 0; i < n; ++i) {
                    while (j < n && a[j] - a[i] < p) {
                        ++j;
                    }

                    while(k < n && a[k] - a[i] < (p << 1)) {
                        ++k;
                    }

                    if(j < n && a[j] - a[i] == p && k < n && a[k] - a[i] == (p << 1)) {
                        out.println(3);
                        out.println(a[i] + " " + a[j] + " " + a[k]);
                        return;
                    }
                }
            }

            for(int p = 1; p != -2147483648; p <<= 1) {
                int j = 0;
                for (int i = 0; i < n; ++i) {
                    while (j < n && a[j] - a[i] < p) {
                        ++j;
                    }

                    if(j < n && a[j] - a[i] == p) {
                        out.println(2);
                        out.println(a[i] + " " + a[j]);
                        return;
                    }
                }
            }

            out.println(1);
            out.print(a[0]);
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