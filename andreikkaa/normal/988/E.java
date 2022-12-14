//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        int f(int a, int b, int c, int d) {
            if(a < c) {
                return b - a + d - c;
            }

            if(a == d && b == c) {
                return 1;
            }

            return b - a + d - c + 1;
        }

        void run(Scanner in, PrintWriter out) {
            String s = in.next();
            int n = s.length();

            if(n == 1) {
                out.print(-1);
                return;
            }

            int ans = 228;
            for(char c : new char[]{'2', '5', '7'}) {
                char d = '5';
                if(c == '5') {
                    d = '0';
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (s.charAt(i) != c || s.charAt(j) != d) {
                            continue;
                        }

                        if (Math.min(i, j) == 0 && Math.max(i, j) != 1 && s.charAt(1) == '0') {
                            int cnt = 0;
                            int k;
                            for(k = 1; k < n && s.charAt(k) == '0'; ++k, ++cnt);
                            if(k == n) {
                                cnt = 229;
                            }
                            ans = Math.min(ans, f(i, n - 2, j, n - 1) + cnt);
                        } else {
                            ans = Math.min(ans, f(i, n - 2, j, n - 1));
                        }
                    }
                }
            }

            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if(s.charAt(i) == '0' && s.charAt(j) == '0') {
                        ans = Math.min(ans, f(i, n - 2, j, n - 1));
                    }
                }
            }

            if(ans == 228) {
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