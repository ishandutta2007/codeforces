//package com.company;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String ss = in.next();
        char[] s = ss.toCharArray();

        for(int i = 0; i + 1 < n; ++i) {
            if(s[i] == s[i + 1] && s[i] != '?') {
                System.out.print("No");
                return;
            }
        }
        
        if(s[0] == '?' || s[n - 1] == '?') {
            System.out.print("Yes");
            return;
        }

        for(int i = 1; i < n - 1; ++i) {
            if(s[i] == '?') {
                if(s[i + 1] == '?') {
                    System.out.print("Yes");
                    return;
                } else if(s[i + 1] == s[i - 1]) {
                    System.out.print("Yes");
                    return;
                }
            }
        }

        System.out.print("No");
    }
}