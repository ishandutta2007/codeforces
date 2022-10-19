import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s=sc.next();
        int cnt=0;

        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='4' || s.charAt(i)=='7')
            {
                cnt++;
            }
        }

        int x=cnt;

        while (x != 0) {
            if (x % 10 == 4 || x % 10 == 7) {
                if (x > 9) {
                    x /= 10;
                } else {
                    System.out.println("YES");
                    return;
                }
            } else {
                break;
            }
        }

        System.out.println("NO");
    }

}