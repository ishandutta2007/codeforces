//package com.company;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            String[] a = new String[n];
            for(int i = 0; i < n; ++i) {
                a[i] = in.next();
            }

            int[] cnt = new int[m];
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(a[j].charAt(i) == '1') {
                        ++cnt[i];
                    }
                }
            }

            for(int i = 0; i < n; ++i) {
                boolean st = true;
                for(int j = 0; j < m; ++j) {
                    if(cnt[j] == 1 && a[i].charAt(j) == '1') {
                        st = false;
                        break;
                    }
                }
                if(st) {
                    out.print("YES");
                    return;
                }
            }
            out.print("NO");
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}