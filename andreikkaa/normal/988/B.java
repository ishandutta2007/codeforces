//package com.company;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static class Task {
        void run(Scanner in, PrintWriter out) {
            int n = in.nextInt();

            ArrayList<String> a = new ArrayList<>(n);
            for(int i = 0; i < n; ++i) {
                a.add(in.next());
            }

            a.sort(Comparator.comparingInt(String::length));

            for(int i = 1; i < n; ++i) {

                boolean ok = false;
                for(int j = 0; j + a.get(i - 1).length() <= a.get(i).length(); ++j) {
                    if(a.get(i).substring(j, j + a.get(i - 1).length()).equals(a.get(i - 1))) {
                        ok = true;
                        break;
                    }
                }

                if(!ok) {
                    out.print("NO");
                    return;
                }
            }

            out.println("YES");
            for(String i : a) {
                out.println(i);
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