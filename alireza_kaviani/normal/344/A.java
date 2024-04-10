//package codeforces;

import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static boolean xor(boolean x, boolean y) {
        boolean t = x || y;
        t = t && !(x && y);
        return t;
    }

    public static void main(String args[]) {
        int n=sc.nextInt(),ans=0;

        String last="";

        for(int i=0;i< n;i++)
        {
           String now=sc.next();

           if(!now.equals(last))
           {
               last=now;
               ans++;
           }
        }

        System.out.println(ans);
    }

}