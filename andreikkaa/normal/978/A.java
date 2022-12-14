//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();

            int[] a = new int[n];
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            ArrayList<Integer> ans = new ArrayList<>();
            for(int i = 0; i < n; ++i) {
                boolean ok = true;
                for(int j = i + 1; j < n; ++j) {
                    if(a[i] == a[j]) {
                        ok = false;
                    }
                }

                if(ok) {
                    ans.add(a[i]);
                }
            }

            out.println(ans.size());
            for(Integer i : ans) {
                out.print(i + " ");
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