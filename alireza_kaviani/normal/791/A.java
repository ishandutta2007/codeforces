import java.util.*;

import static java.lang.Math.*;

public class codeforces3 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        problem_8 a = new problem_8();

    }

    static class problem_1 {
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
        problem_3() {
            int n = sc.nextInt();
            int maxn = sc.nextInt(), minn = maxn;

            int ans = 0;
            for (int i = 0; i < n - 1; i++) {
                int t = sc.nextInt();

                if (t > maxn) {
                    ans++;
                    maxn = t;
                }
                if (t < minn) {
                    ans++;
                    minn = t;
                }
            }

            System.out.print(ans);
        }
    }

    static class problem_4 {
        problem_4() {
            int ans = 0;
            int past = -5;
            boolean b = true;
            for (int i = 0; i < 5; i++) {
                int n = sc.nextInt();
                if (past != -5 && past != n) {
                    b = false;
                }
                past = n;
                ans += n;
            }

            System.out.printf("%d", (ans % 5 != 0 || b && past == 0) ? -1 : ans / 5);
        }
    }

    static class problem_5 {
        problem_5() {
            int n = sc.nextInt();
            int a[] = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int sum = 0;
                    for (int k = 0; k < n; k++) {
                        if (k >= i && k <= j) {
                            sum += 1 - a[k];
                        } else {
                            sum += a[k];
                        }
                    }
                    ans = max(ans, sum);
                }
            }

            System.out.printf("%d", ans);
        }
    }

    static class problem_6 {
        problem_6() {
            int m = sc.nextInt(), n = sc.nextInt();

            if (m*9<n || (n==0 && m!=1)){
                System.out.printf("%s", "-1 -1");
                return;
            }
            if(n==0 && m==1)
            {
                System.out.printf("%s","0 0 ");
                return;
            }

            int x = n;
            String maxn = "";
            String minn = "";
            for (int i = 0; i < m; i++) {
                for (int j = 9; j >= 0; j--) {
                    if (j <= x) {
                        x -= j;
                        maxn += String.valueOf(j);

                        if (x == 0 && j != 0 && i != m - 1) {
                            minn = String.valueOf(j - 1) + minn;
                        } else if (x == 0 && j == 0 && i == m - 1) {
                            minn = "1" + minn;
                        } else if (x == 0 && j == 0 && i != m - 1) {
                            minn = "0" + minn;
                        } else {
                            minn = String.valueOf(j) + minn;
                        }
                        break;
                    }
                }
            }

            System.out.printf("%s %s", minn, maxn);
        }
    }

    static class problem_7
    {
        problem_7()
        {
            int n=sc.nextInt();

            int ans=0;
            int add=1;
            int add2=1;
            for(int i=0;i<n;i++)
            {
                ans+=add;
                add+=add2++;
            }
            System.out.printf("%d",ans);
        }
    }

    static class problem_8
    {
        problem_8()
        {
            double n=sc.nextDouble(),m=sc.nextDouble();

            int i=0;
            while(m>=n)
            {
                m*=2;
                n*=3;
                i++;
            }
            System.out.printf("%d",i);
        }
    }
}