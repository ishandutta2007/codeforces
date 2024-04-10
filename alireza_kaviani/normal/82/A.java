//package codeforces;

import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt();

        while(n>5)
        {
            n-=5;
            n=(n+1)/2;
        }

        String a[]= {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

        System.out.println(a[n-1]);
    }

}