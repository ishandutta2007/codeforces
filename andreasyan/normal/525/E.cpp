#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 26;

int n, k;
long long S;
vector<int> a, b;

map<long long, int> mp[N];

long long f[N];

int main()
{
    scanf("%d%d%lld", &n, &k, &S);
    for (int i = 0; i < n / 2; ++i)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    for (int i = n / 2; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }
    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = min(S + 1, f[i - 1] * i);
    for (int x = 0; x < (1 << a.size()); ++x)
    {
        for (int y = x; ; y = (y - 1) & x)
        {
            int q = 0;
            for (int i = 0; i < a.size(); ++i)
            {
                if ((y & (1 << i)))
                    ++q;
            }
            long long s = 0;
            for (int i = 0; i < a.size(); ++i)
            {
                if ((x & (1 << i)))
                {
                    if (!(y & (1 << i)))
                        s = min(S + 1, s + a[i]);
                    else
                    {
                        if (a[i] < N)
                            s = min(S + 1, s + f[a[i]]);
                        else
                            s = S + 1;
                    }
                }
            }
            if (s <= S)
                mp[q][s]++;
            if (y == 0)
                break;
        }
    }
    long long ans = 0;
    for (int x = 0; x < (1 << b.size()); ++x)
    {
        for (int y = x; ; y = (y - 1) & x)
        {
            int q = 0;
            for (int i = 0; i < b.size(); ++i)
            {
                if ((y & (1 << i)))
                    ++q;
            }
            long long s = 0;
            for (int i = 0; i < b.size(); ++i)
            {
                if ((x & (1 << i)))
                {
                    if (!(y & (1 << i)))
                        s = min(S + 1, s + b[i]);
                    else
                    {
                        if (b[i] < N)
                            s = min(S + 1, s + f[b[i]]);
                        else
                            s = S + 1;
                    }
                }
            }
            if (s <= S)
            {
                for (int i = 0; i <= k - q; ++i)
                {
                    if (mp[i].find(S - s) != mp[i].end())
                        ans += mp[i][S - s];
                }
            }
            if (y == 0)
                break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}