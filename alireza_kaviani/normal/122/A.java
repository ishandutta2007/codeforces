import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                int x = i;

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
            }
        }

        System.out.println("NO");
    }

}