import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt(), ans = 0;

        boolean a[] = new boolean[n];

        int x=sc.nextInt();
        for (int i = 0; i < x; i++) {
            a[sc.nextInt() - 1] = true;
        }

        x=sc.nextInt();
        for (int i = 0; i < x; i++) {
            a[sc.nextInt() - 1] = true;
        }

        for (int i = 0; i < a.length; i++) {
            if (a[i] != true) ans++;
        }

        if (ans == 0) System.out.println("I become the guy.");
        else System.out.println("Oh, my keyboard!");
    }

}