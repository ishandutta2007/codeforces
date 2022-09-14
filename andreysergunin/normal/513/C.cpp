#include <bits/stdc++.h>

using namespace std;
const int MAXN = 30;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    int l[MAXN], r[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &l[i], &r[i]);

    int t = 1 << n;

    double ans = 0;
    bool f;
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j < t; j++)
        {
            int u[5];
            int v = j;
            int g = 0;
            for (int k = 0; k < n; k++)
            {
                u[k] = v % 2;
                if (u[k] == 1)
                    g ++;
                v /= 2;
            }
            if (g > 1)
            {
                f = true;
                for (int k = 0; k < n; k++)
                {
                    if (u[k] == 1)
                    {

                        if (l[k] > i || i > r[k])
                            f = false;
                    }
                    else
                    {
                        if (l[k] >= i)
                            f = false;
                    }
                }
                if (f)
                {

                    int p[5];
                    for (int k = 0; k < n; k++)
                        if (u[k] == 0)
                            p[k] = min(r[k] + 1, i) - l[k];
                        else
                            p[k] = 1;
                    double q = 1;
                    for (int k = 0; k < n; k++)
                        q *= (double) p[k] / (r[k] - l[k] + 1);
                    ans += (double) q * i;
                }

            }



            for (int z = 0; z < n; z++)
                if (u[z] == 0 && r[z] > i)
                {

                    f = true;
                    for (int k = 0; k < n; k++)
                        if (k != z)
                        {
                            if (u[k] == 1)
                            {
                                if (l[k] > i || i > r[k])
                                    f = false;
                            }
                            else
                            {
                                if (l[k] >= i)
                                    f = false;
                            }
                        }

                    if (f)
                    {
                        //printf("%d %d\n", j, z);
                        int p[5];
                        for (int k = 0; k < n; k++)
                            if (k != z)
                            {
                                if (u[k] == 0)
                                    p[k] = min(r[k] + 1, i) - l[k];
                                else
                                    p[k] = 1;
                            }

                        p[z] = r[z] - max(i, l[z] - 1);

                        /*for (int k = 0; k < n; k++)
                            printf("%d ", p[k]);
                        printf("\n");*/

                        double q = 1;
                        for (int k = 0; k < n; k++)
                            q *= (double) p[k] / (r[k] - l[k] + 1);

                        ans += (double) q * i;
                    }
                }
        }
    }
    printf("%.15lf", ans);
    return 0;
}