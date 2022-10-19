import java.util.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static int gcd(int a, int b) {
        if (a == 0 && b == 0) {
            return -1;
        }
        if (a < b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }

        if (a % b == 0) {
            return b;
        }

        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        int a[] = new int[2];
        a[0] = sc.nextInt();
        a[1] = sc.nextInt();
        int n = sc.nextInt();

        int i = 0;
        while (n != 0) {
            int t = gcd(a[i%2], n);
            if (t == -1) {
                break;
            }
            n -= t;
            i++;
        }

        System.out.println(1-i%2);
    }

}