//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            long[] a = new long[n];
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextLong();
                if(i > 0) {
                    a[i] += a[i - 1];
                }
            }

            for(int i = 0; i < m; ++i) {
                long x = in.nextLong();
                int pos = Arrays.binarySearch(a, x);

                if(pos < 0) {
                    pos = -pos - 1;
                }

                assert pos < n;

                if(pos == 0) {
                    out.println(1 + " " + x);
                } else {
                    out.println((pos + 1) + " " + (x - a[pos - 1]));
                }
            }
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