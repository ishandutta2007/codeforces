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
        String s=sc.next();
        String s1=sc.next();

        for(int i=0;i<s.length();i++)
        {
            boolean x=(s.charAt(i)=='1')?true:false;
            boolean y=(s1.charAt(i)=='1')?true:false;

            if(xor(x,y))
            {
                System.out.print(1);
            }
            else
            {
                System.out.print(0);
            }
        }
    }

}