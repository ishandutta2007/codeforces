//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int a = in.nextInt();
            int n = in.nextInt();
            int m = in.nextInt();

            boolean[] bad = new boolean[a + 1];
            for(int i = 0; i < n; ++i) {
                int l = in.nextInt();
                int r = in.nextInt();

                for(; l < r; ++l) {
                    bad[l] = true;
                }
            }

            int[] w = new int[a + 1];
            for(int i = 0; i < m; ++i) {
                int x = in.nextInt();
                int p = in.nextInt();

                if(w[x] == 0 || p < w[x]) {
                    w[x] = p;
                }
            }

            HashMap<Integer, Integer> was = new HashMap<>();
            was.put(0, 0);

            for(int i = 0; i < a; ++i) {
                HashMap<Integer, Integer> now = new HashMap<>();

                for(Map.Entry<Integer, Integer> j : was.entrySet()) {
                    if(bad[i]) {
                        int val = Integer.MAX_VALUE;
                        if(j.getKey() == 0) {
                            if(w[i] != 0) {
                                val = w[i];
                            }
                        } else {
                            if(w[i] != 0) {
                                val = Math.min(w[i], j.getKey());
                            } else {
                                val = j.getKey();
                            }
                        }

                        if(val != Integer.MAX_VALUE) {
                            int ans = j.getValue() + val;
                            if (now.containsKey(val)) {
                                ans = Math.min(ans, now.get(val));
                            }
                            now.put(val, ans);
                        }
                    } else {
                        int ans = j.getValue() + j.getKey();
                        if(now.containsKey(j.getKey())) {
                            ans = Math.min(ans, now.get(j.getKey()));
                        }
                        now.put(j.getKey(), ans);

                        ans = j.getValue();
                        if(now.containsKey(0)) {
                            ans = Math.min(ans, now.get(0));
                        }
                        now.put(0, ans);

                        if(w[i] != 0) {
                            ans = j.getValue() + w[i];
                            if(now.containsKey(w[i])) {
                                ans = Math.min(ans, now.get(w[i]));
                            }
                            now.put(w[i], ans);
                        }
                    }
                }

                was = now;

                /*out.println(i + 1);
                for(Map.Entry<Integer, Integer> j : was.entrySet()) {
                    out.println(j.getKey() + " " + j.getValue());
                }
                out.println();*/
            }

            int ans = Integer.MAX_VALUE;
            for(Integer i : was.values()) {
                ans = Math.min(ans, i);
            }
            if(ans == Integer.MAX_VALUE) {
                ans = -1;
            }
            out.print(ans);
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