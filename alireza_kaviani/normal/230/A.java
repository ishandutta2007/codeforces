import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int n = sc.nextInt(), m = sc.nextInt();
        int l[][] = new int[m][2];

        for (int i = 0; i < m; i++) {
            l[i][0] = sc.nextInt();
            l[i][1] = sc.nextInt();
        }

        Arrays.sort(l, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });

        int i;
        for (i = 0; i < m; i++) {
            if (n > l[i][0]) {
                n += l[i][1];
            } else {
                break;
            }
        }

        System.out.println((i == m) ? "YES" : "NO");
    }

}