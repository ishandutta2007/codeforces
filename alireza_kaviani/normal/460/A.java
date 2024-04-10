//package codeforces;

import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n=sc.nextInt(),m=sc.nextInt(),i;

        for(i=1;i<100000;i++)
        {
            n--;

            if(i%m==0)n++;

            if(n==0)break;
        }

        System.out.println(i);
    }

}