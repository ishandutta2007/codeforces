//package com.company;

import java.io.PrintWriter;
import java.util.*;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            String s = in.next();

            int ans = 0;
            int bal = 0;

            for(int i = 0; i < n; ++i) {
                if(s.charAt(i) == 'x') {
                    ++bal;
                } else {
                    bal = 0;
                }

                if(bal == 3) {
                    --bal;
                    ++ans;
                }
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