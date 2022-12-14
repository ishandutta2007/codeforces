//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            Integer[] r = new Integer[n];
            for(int i = 0; i < n; ++i) {
                r[i] = in.nextInt();
            }

            ArrayList<Integer> rs = new ArrayList<>(Arrays.asList(r));
            Collections.sort(rs);

            ArrayList<ArrayList<Integer>> g = new ArrayList<>();
            for(int i = 0; i <= n; ++i) {
                g.add(new ArrayList<>());
            }

            for(int i = 0; i < m; ++i) {
                int a = in.nextInt();
                int b = in.nextInt();

                g.get(a).add(b);
                g.get(b).add(a);
            }

            for(int i = 1; i <= n; ++i) {
                int ans = lowerBound(rs, r[i - 1]);
                for(int j : g.get(i)) {
                    if(r[j - 1] < r[i - 1]) {
                        --ans;
                    }
                }

                out.println(ans);
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

    static public <T extends Comparable<T>> int lowerBound(List<T> a, T x) {
        int l = 0;
        int r = a.size();
        while(l != r) {
            int m = (l + r) / 2;
            if(a.get(m).compareTo(x) < 0) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    static public <T extends Comparable<T>> int upperBound(List<T> a, T x) {
        int l = 0;
        int r = a.size();
        while(l != r) {
            int m = (l + r) / 2;
            if(a.get(m).compareTo(x) <= 0) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}