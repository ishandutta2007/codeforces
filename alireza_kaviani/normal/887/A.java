//package codeforces;

import java.util.*;

public class codeforces4
{
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String s=sc.next();
        int t=0;
        boolean b=false;

        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)=='1')
            {
                b=true;
            }
            if(b && s.charAt(i)=='0')
            {
                t++;
            }
        }

        if(t>=6)
        {
            System.out.println("yes");
        }
        else
        {
            System.out.println("no");
        }
    }
}