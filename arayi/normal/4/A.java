//package com.example.helloworld;

import java.util.*;

public class HelloWorld {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n!=2&&n%2==0) System.out.println("Yes");
        else System.out.println("No");
    }
}