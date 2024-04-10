import java.lang.*;
import java.io.*;
import java.util.*;

public class B {
    static Scanner in;
    public static void main(String[] args) {
        in = new Scanner(System.in);
        String s = in.nextLine();
        boolean flag = false;
        char ch = 'H';
        //if (s.charAt(0) == ch)
            //ch = '3';
       for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) == 'H' || s.charAt(i) == 'Q' || s.charAt(i) == '9')
                flag = true;
        if (flag)
            System.out.println("YES\n");
        else
            System.out.println("NO\n");
    }
}