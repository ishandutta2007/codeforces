import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        long n = sc.nextLong();

        if (n % 2 == 0) {
            System.out.println(n / 2);
        } else {
            System.out.println(-n + (n - 1) / 2);
        }
    }

}