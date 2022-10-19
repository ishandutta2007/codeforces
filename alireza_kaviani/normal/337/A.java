import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt(), k = sc.nextInt(), min = 1000000;
        int p[] = new int[k];

        for (int i = 0; i < k; i++) {
            p[i] = sc.nextInt();
        }

        Arrays.sort(p);

        for (int i = 0; i <= k - n; i++) {
            if (min > p[i + n - 1] - p[i]) {
                min = p[i + n - 1] - p[i];
            }
        }

        System.out.println(min);
    }

}