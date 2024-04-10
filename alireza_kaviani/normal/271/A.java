import java.util.*;


public class codeforces2 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        int n = sc.nextInt();
        int x = n;

        boolean a[] = new boolean[10];

        while (x++ != 0) {
            for(int i=0;i<10;i++)a[i]=false;

            int y = x;
            while (y != 0) {
                a[y % 10] = true;
                y /= 10;
            }

            int cnt = 0;

            for (boolean i : a) {
                if (i) {
                    cnt++;
                }
            }

            if (cnt == 4) {
                break;
            }
        }

        System.out.println(x);
    }

}