import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s=sc.next();

        for (int i = 0; i < s.length() ; i++) {
            char t=s.charAt(i);

            if(t=='H' || t=='Q' || t=='9')
            {
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }

}