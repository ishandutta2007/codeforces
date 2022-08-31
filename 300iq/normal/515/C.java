//package com.company;

import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n;
        String s;
        String k = "";
        n = in.nextInt();
        s = in.next();
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '2') {
                k += '2';
            }
            if (s.charAt(i) == '3') {
                k += '3';
            }
            if (s.charAt(i) == '4') {
                k += "322";
            }
            if (s.charAt(i) == '5') {
                k += '5';
            }
            if (s.charAt(i) == '6') {
                k += "53";
            }
            if (s.charAt(i) == '7') {
                k += '7';
            }
            if (s.charAt(i) == '8') {
                k += "7222";
            }
            if (s.charAt(i) == '9') {
                k += "7332";
            }
        }
        char[] chars = k.toCharArray();
        Arrays.sort(chars);
        s = new String(chars);
        for(int i = s.length() - 1; i >= 0; i--) {
            System.out.print(s.charAt(i));
        }
    }
}