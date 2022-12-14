//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        int f(int[] a) {
            int x = a[1] - a[0];
            int ans = 0;
            for(int i = 2; i < a.length; ++i) {
                if(a[i] - a[i - 1] != x) {
                    if(Math.abs(a[i] - a[i - 1] - x) > 1) {
                        return a.length + 1;
                    }

                    ++ans;
                    a[i] = a[i - 1] + x;
                }
            }

            return ans;
        }

        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();

            if(n == 1) {
                out.println(0);
                return;
            }

            int[] a = new int[n];
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            int ans = n + 1;
            for(int i = -1; i <= 1; ++i) {
                for(int j = -1; j <= 1; ++j) {
                    int[] b = a.clone();
                    b[0] += i;
                    b[1] += j;
                    ans = Math.min(ans, f(b) + (i != 0 ? 1 : 0) + (j != 0 ? 1 : 0));
                }
            }

            if(ans == n + 1) {
                ans = -1;
            }
            out.println(ans);
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