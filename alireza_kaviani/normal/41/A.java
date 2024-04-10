import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        String s = sc.next();
        String c = sc.next();
        char a[] = s.toCharArray();
        char b[] = new char[c.length()];

        boolean ans = true;

        for (int i = 0; i < c.length(); i++) {
            b[i] = c.charAt(c.length() - i - 1);
        }

        if (Arrays.equals(a, b)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

}