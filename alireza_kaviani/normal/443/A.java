//package codeforces;

import java.util.*;

public class codeforces3{
    private static Scanner sc=new Scanner(System.in);

    public static void main(String[] args) {
        Set<Character> s=new HashSet<>();

        char c=sc.findInLine(".").charAt(0);

        while(c!='}')
        {
            c=sc.findInLine(".").charAt(0);
            if(c!=',' && c!='}')
            {
                s.add(c);
            }
        }

        int ans=s.size();

        if(ans>1)ans--;

        System.out.println(ans);
    }
}