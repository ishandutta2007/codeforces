import java.util.*;

import static java.lang.Math.*;

public class codeforces1 {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String args[]) {
        problem_10 a = new problem_10();
    }

    static class problem_1 {
        problem_1() {
            int n = sc.nextInt(), ans = 0;
            double cnt[] = new double[5];

            for (int i = 0; i < n; i++) {
                cnt[sc.nextInt()]++;
            }

            ans += cnt[4];
            ans += cnt[3];

            cnt[1] -= cnt[3];

            if (cnt[1] < 0) cnt[1] = 0;

            ans += Math.ceil(cnt[2] / 2);
            cnt[2] %= 2;

            if (cnt[2] == 1) {
                cnt[1] -= 2;
                if (cnt[1] < 0) cnt[1] = 0;
            }

            ans += Math.ceil(cnt[1] / 4);

            System.out.println(ans);
        }
    }

    static class problem_2 {
        problem_2() {
            int n = sc.nextInt(), k = 240 - sc.nextInt();
            int t = 5;

            int ans = 0;
            while (k - t >= 0) {
                k -= t;
                t += 5;
                ans++;
            }

            System.out.println(min(ans, n));
        }
    }

    static class problem_3 {
        public int function(int n) {
            return n * (n + 1) / 2;
        }

        problem_3() {
            int n = sc.nextInt();
            int ans = 0, t = 0;

            for (int i = 1; i <= n; i++) {
                if (t + function(i) > n) break;
                t += function(i);
                ans++;
            }

            System.out.println(ans);
        }
    }

    static class problem_4 {
        problem_4() {
            int n = sc.nextInt(), m = sc.nextInt();
            if (n == 1 && m == 10) {
                System.out.println(-1);
            } else {
                m = ((m == 10) ? (1) : m);
                System.out.print(m);
                for (int i = 1; i < n; i++) {
                    System.out.print(0);
                }
            }
        }
    }

    static class problem_5 {
        public boolean check(int a, int b) {
            return (a % 10 == 0 || a % 10 == b);
        }

        problem_5() {
            int n = sc.nextInt(), m = sc.nextInt();

            int ans = 0;
            for (int i = 1; i <= 10; i++) {
                if (check(n * i, m)) {
                    ans = i;
                    break;
                }
            }

            System.out.println(ans);
        }
    }

    static class problem_6 {
        problem_6() {
            long a = sc.nextLong(), b = sc.nextLong();
            long x = sc.nextLong(), y = sc.nextLong(), z = sc.nextLong();

            a -= 2 * x;
            b -= 3 * z;
            a -= y;
            b -= y;

            long ans = 0;
            if (b < 0) {
                ans += -b;
            }
            if (a < 0) {
                ans += -a;
            }

            System.out.print(ans);
        }
    }

    static class problem_7 {
        problem_7() {
            int n = sc.nextInt();
            HashMap<String, Integer> mp = new HashMap<>();

            for (int i = 0; i < n; i++) {
                String s = sc.next();

                if (!mp.containsKey(s)) {
                    mp.put(s, 0);
                    System.out.println("OK");
                } else {
                    mp.put(s, mp.get(s) + 1);
                    System.out.println(s + "" + mp.get(s));
                }
            }
        }
    }

    static class problem_8 {
        problem_8() {
            int n = sc.nextInt(), k = sc.nextInt();

            int ans = 0;
            for (int i = 0; i < n; i++) {
                int t = sc.nextInt();
                if (t + k <= 5) {
                    ans++;
                }
            }

            System.out.println(ans / 3);
        }
    }

    static class problem_9 {
        problem_9() {
            int n = sc.nextInt();
            String s = sc.next(), t = sc.next();

            int ans=0;
            for (int i = 0; i < n; i++) {
                int m = Integer.parseInt(String.valueOf(s.charAt(i)));
                int k = Integer.parseInt(String.valueOf(t.charAt(i)));
                if (m < k) {
                    int temp = k;
                    k = m;
                    m = temp;
                }

                int temp =min(m-k,abs(10+k-m));
                ans+=temp;
            }
            System.out.println(ans);
        }
    }

    static class problem_10
    {
        problem_10()
        {
            int n=sc.nextInt();

            int t=0 , ans=0;
            for(int i=0;i<n;i++)
            {
                int m=sc.nextInt();
                if(m>=0)
                {
                    t+=m;
                }
                else if(t>=-m)
                {
                    t+=m;
                }
                else
                {
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}