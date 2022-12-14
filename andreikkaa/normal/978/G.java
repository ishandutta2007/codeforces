//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            int[] s = new int[m];
            int[] d = new int[m];
            int[] c = new int[m];
            for(int i = 0; i < m; ++i) {
                s[i] = in.nextInt();
                d[i] = in.nextInt();
                c[i] = in.nextInt();
            }

            TreeSet<Integer> st = new TreeSet<>(Comparator.comparingInt(x -> d[x]));
            ArrayList<Integer> ans = new ArrayList<>();

            for(int i = 1; i <= n; ++i) {
                boolean can = true;

                for(int j = 0; j < m; ++j) {
                    if(d[j] == i) {
                        can = false;
                        if(c[j] != 0) {
                            out.println(-1);
                            return;
                        }
                        ans.add(m + 1);
                    }
                }

                for(int j = 0; j < m; ++j) {
                    if(s[j] == i) {
                        st.add(j);
                    }
                }

                if(can) {
                    if (st.isEmpty()) {
                        ans.add(0);
                    } else {
                        int j = st.first();
                        st.remove(j);
                        --c[j];
                        if (c[j] > 0) {
                            st.add(j);
                        }
                        ans.add(j + 1);
                    }
                }
            }

            for(int i : ans) {
                out.println(i);
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