//package com.company;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int l = in.nextInt();
            int s = n * k;

            Integer[] a = new Integer[s];
            for(int i = 0; i < s; ++i) {
                a[i] = in.nextInt();
            }

            Arrays.sort(a);
            int pos;
            for(pos = 0; pos < s; ++pos) {
                if(a[pos] - a[0] > l) {
                    break;
                }
            }

            if(pos < n) {
                out.print(0);
                return;
            }

            int cnt = 0;
            long ans = 0;
            boolean u[] = new boolean[s];
            for(int i = 0; i < pos && cnt < n; i += k) {
                u[i] = true;
                ++cnt;
                ans += a[i];
            }

            for(int i = pos - 1; i >= 0 && cnt < n; --i) {
                if(!u[i]) {
                    u[i] = true;
                    ++cnt;
                    ans += a[i];
                }
            }

            if(cnt != n) {
                System.exit(0);
            }
            out.print(ans);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}