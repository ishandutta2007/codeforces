//package codeforces;

import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int a=sc.nextInt(),b=sc.nextInt(),ret=0,zen=0;

        while(a>0)
        {
            ret+=a;
            zen+=a;
            a=zen/b;
            zen%=b;
        }

        System.out.println(ret);
    }

}