import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {

    public static void main(String[] args) {

        problem_3 a = new problem_3();

    }

    static class problem_1 {
        private static Scanner sc = new Scanner(System.in);

        problem_1() {
            int n = sc.nextInt();
            double ans = 0;

            for (int i = 0; i < n; i++) {
                ans += sc.nextDouble();
            }

            System.out.printf("%.10f", ans / (double) n);
        }
    }

    static class problem_2 {
        private static Scanner sc = new Scanner(System.in);

        problem_2() {
            int n = sc.nextInt();
            String[] s = new String[2];

            s[0] = "I hate";
            s[1] = "I love";

            for (int i = 0; i < n; i++) {
                System.out.print(s[i % 2] + ((i != n - 1) ? " that " : " it"));
            }
        }
    }

    static class problem_3 {
        private static Scanner sc = new Scanner(System.in);

        problem_3() {
            int n = sc.nextInt();
            int maxn = sc.nextInt(), minn = maxn;

            int ans=0;
            for (int i = 0; i < n - 1; i++) {
                int t = sc.nextInt();

                if(t>maxn)
                {
                    ans++;
                    maxn=t;
                }
                if(t<minn)
                {
                    ans++;
                    minn=t;
                }
            }

            System.out.print(ans);
        }
    }
}