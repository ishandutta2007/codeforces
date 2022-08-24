#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 316;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("accounts.in", "r", stdin);
    //freopen("accounts.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    vector <int> t_(m);
    vector <int> a_(m), b_(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &t_[i]);
        if (t_[i])
        {
            scanf("%d", &a_[i]);
            a_[i]--;
        }
        else
        {
            scanf("%d%d", &a_[i], &b_[i]);
            a_[i]--;
        }
    }
    for (int i = 0; i < m; i += sz)
    {
        vector <bool> used(n);
        int en = min(i + sz, m);
        for (int j = i; j < en; j++)
        {
            if (!t_[j])
            {
                used[a_[j]] = true;
            }
        }
        vector <int> last(n);
        vector <int> f_u(n);
        vector <int> cnt(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (used[i])
            {
                f_u[i] = i;
                cnt[i] = 0;
                last[i] = -1;
                continue;
            }
            if (i + a[i] >= n)
            {
                last[i] = i;
                f_u[i] = -1;
                cnt[i] = 1;
            }
            else
            {
                if (last[i + a[i]] != -1)
                {
                    last[i] = last[i + a[i]];
                    cnt[i] = cnt[i + a[i]] + 1;
                    f_u[i] = -1;
                }
                else
                {
                    last[i] = -1;
                    cnt[i] = cnt[i + a[i]] + 1;
                    f_u[i] = f_u[i + a[i]];
                }
            }
        }
        for (int j = i; j < en; j++)
        {
            if (!t_[j])
            {
                a[a_[j]] = b_[j];
            }
            else
            {
                int x = a_[j];
                int sum = 0;
                while (1)
                {
                    if (used[x])
                    {
                        sum++;
                        if (x + a[x] >= n)
                        {
                            break;
                        }
                        x += a[x];
                    }
                    else
                    {
                        if (last[x] == -1)
                        {
                            sum += cnt[x];
                            x = f_u[x];
                        }
                        else
                        {
                            sum += cnt[x];
                            x = last[x];
                            break;
                        }
                    }
                }
                printf("%d %d\n", x + 1, sum);
            }
        }
    }
}