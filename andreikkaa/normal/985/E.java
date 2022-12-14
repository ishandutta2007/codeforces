//package com.company;

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class Task {
        int[] fenwick;

        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int d = in.nextInt();

            int[] a = new int[n + 1];
            for(int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            a[n] = -1000 * 1000 * 1000;

            Arrays.sort(a);
            fenwick = new int[n + 1];

            update(0);

            boolean ok = false;
            for(int i = k; i < n + 1; ++i) {
                ok = false;
                int l = 0;
                int r = i;
                while(l != r) {
                    int m = (l + r) / 2;
                    if(a[m] + d < a[i]) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }

                if(get(i - k) - get(l - 2) > 0) {
                    ok = true;
                    update(i);
                }
            }

            out.print(ok ? "YES" : "NO");
        }

        void update(int pos) {
            ++pos;
            for(; pos < fenwick.length; pos |= (pos + 1)) {
                ++fenwick[pos];
            }
        }

        int get(int pos) {
            ++pos;
            int sum = 0;
            for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
                sum += fenwick[pos];
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}