import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt(), e = sc.nextInt(), ans = 0;

        for (int i = 1; i < e + 1; i++) {
            if (i % a != 0 && i % b != 0 && i % c != 0 && i % d != 0) ans++;
        }

        System.out.println(e - ans);
    }

}