//package com.company;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();

            int[] a = new int[n / 2];
            for(int i = 0; i < n / 2; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);

            int a1 = 0;
            for(int i = 0; i < n / 2; ++i) {
                a1 += Math.abs(2 * i + 1 - a[i]);
            }

            int a2 = 0;
            for(int i = 0; i < n / 2; ++i) {
                a2 += Math.abs(2 * i + 2 - a[i]);
            }

            out.print(Math.min(a1, a2));
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Task().run(in, out);
        out.flush();
    }
}