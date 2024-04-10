#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006;

int n;
vector<int> a[N];

int qq;

int s[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        bool z = false;
        for (int j = 1; j < a[i].size(); ++j)
        {
            if (a[i][j - 1] < a[i][j])
            {
                z = true;
                break;
            }
        }
        if (z)
        {
            ++qq;
            continue;
        }
        s[a[i][0]]++;
    }
    for (int i = N - 2; i >= 0; --i)
        s[i] += s[i + 1];
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        bool z = false;
        for (int j = 1; j < a[i].size(); ++j)
        {
            if (a[i][j - 1] < a[i][j])
            {
                z = true;
                break;
            }
        }
        if (z)
        {
            ans += n;
            continue;
        }
        ans += qq;
        ans += s[a[i].back() + 1];
    }
    printf("%lld\n", ans);
    return 0;
}