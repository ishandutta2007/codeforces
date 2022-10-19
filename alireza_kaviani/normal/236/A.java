import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s=sc.next();

        Set<Character> a=new HashSet<>();

        for(int i=0;i<s.length();i++)
        {
            a.add(s.charAt(i));
        }

        if(0==a.size()%2)
        {
            System.out.println("CHAT WITH HER!");
            return;
        }

        System.out.println("IGNORE HIM!");
    }

}