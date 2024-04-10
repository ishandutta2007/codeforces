//package com.company;
import java.io.PrintWriter;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        int a[] = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int counter;
        for(int i = 0; i < n; i++) {
            counter = 1;
            for(int j = 0; j < n; j++) {
                if(a[j] > a[i] && i != j) {
                    counter++;
                }
            }
            out.print(counter + " ");
        }
        out.close();
    }
}