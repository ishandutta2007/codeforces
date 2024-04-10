//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            TreeMap<Integer, Pair<Integer, Integer>> m = new TreeMap<>();

            int n = in.nextInt();
            for(int i = 0; i < n; ++i) {
                int k = in.nextInt();
                int[] a = new int[k];
                int sum = 0;
                for(int j = 0; j < k; ++j) {
                    a[j] = in.nextInt();
                    sum += a[j];
                }

                for(int j = 0; j < k; ++j) {
                    Pair<Integer, Integer> p = m.get(sum - a[j]);
                    if(p == null) {
                        m.put(sum - a[j], new Pair<>(i + 1, j + 1));
                    } else if(p.x != i + 1) {
                        out.println("YES");
                        out.println(p.x + " " + p.y);
                        out.println((i + 1) + " " + (j + 1));
                        return;
                    }
                }
            }

            out.print("NO");
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