#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y)
{
    return x ? gcd(y % x, x) : y;
}

int a[200010];
int b[200010];
vector<int> lis[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }

    for(i = 0; i < m; i++)
    {
        int &x = a[i];
        int &y = b[i];
        if(y < x)
            swap(x, y);

        if(y - x > x + n - y)
        {
            x += n;
            swap(x, y);
        }

        if((y - x) * 2 == n)
        {
            lis[y - x].push_back(x);
            lis[y - x].push_back(y % n);
        }
        else
            lis[y - x].push_back(x);
    }

    bool ok = 1;
    long long d = 1;
    for(i = 1; i <= n; i++)
    {
        int sz = (int)lis[i].size();
        if(sz == 0)
            continue;
        if(sz == 1)
        {
            ok = 0;
            break;
        }

        sort(lis[i].begin(), lis[i].end());

        vector<int> dif;
        for(j = 0; j < sz; j++)
            dif.push_back((lis[i][(j + 1) % sz] - lis[i][j] + n) % n);

        const int p1 = 1000003;
        const int p2 = 1000033;
        const int q = 1000000007;

        int h1 = 0;
        int h2 = 0;
        int pn1 = 1;
        int pn2 = 1;
        for(j = 0; j < sz; j++)
        {
            h1 = (1LL * h1 * p1 + dif[j]) % q;
            h2 = (1LL * h2 * p2 + dif[j]) % q;
            pn1 = 1LL * pn1 * p1 % q;
            pn2 = 1LL * pn2 * p2 % q;
        }

        int c1 = h1;
        int c2 = h2;
        int ans = -1;
        int sum = 0;
        for(j = 0; j < sz - 1; j++)
        {
            c1 = (1LL * c1 * p1 + dif[j]) % q;
            c2 = (1LL * c2 * p2 + dif[j]) % q;

            c1 = (c1 - 1LL * dif[j] * pn1 % q + q) % q;
            c2 = (c2 - 1LL * dif[j] * pn2 % q + q) % q;

            sum += dif[j];

            if(c1 == h1 && c2 == h2)
            {
                ans = sum;
                break;
            }
        }
        if(ans == -1)
        {
            ok = 0;
            break;
        }

        d = 1LL * ans * d / gcd(ans, d);
        if(d % n == 0)
        {
            ok = 0;
            break;
        }
    }

    if(ok)
        puts("Yes");
    else
        puts("No");

    return 0;
}