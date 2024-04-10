#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005, M = 998244353;

int n, k;
int a[N];

long long ans1, ans2;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i >= n - k + 1; --i)
        ans1 += i;
    vector<int> v;
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] >= n - k + 1)
        {
            v.push_back(q);
            q = 0;
        }
        else
            ++q;
    }
    v.push_back(q);
    ans2 = 1;
    for (int i = 1; i < (int)v.size() - 1; ++i)
        ans2 = (ans2 * (v[i] + 1)) % M;
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}