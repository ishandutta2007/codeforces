//package com.company;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();

            int[] a = new int[n];
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            ArrayList<Integer> ans = new ArrayList<>();
            for(int i = 0; i < n; ++i) {
                boolean ok = true;
                for(Integer j : ans) {
                    if(a[j] == a[i]) {
                        ok = false;
                        break;
                    }
                }

                if(ok) {
                    ans.add(i);
                }
            }

            if(ans.size() < k) {
                out.print("NO");
                return;
            }

            out.println("YES");
            for(int i = 0; i < k; ++i) {
                out.print(ans.get(i) + 1 + " ");
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}