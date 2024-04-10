#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005;

int n, qq;
int a[N];

int main()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    while (qq--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        long long ans = 0;
        stack<pair<int, int> > s;
        long long yans = 0;
        for (int i = l; i <= r; ++i)
        {
            if (i > l)
            {
                pair<int, int> u = m_p(abs(a[i] - a[i - 1]), 0);
                while (!s.empty() && u.first > s.top().first)
                {
                    yans -= (s.top().first * 1LL * s.top().second);
                    u.second += s.top().second;
                    s.pop();
                }
                yans += (u.first * 1LL * u.second);
                s.push(u);
            }
            s.push(m_p(0, 1));
            ans += yans;
        }
        printf("%lld\n", ans);
    }
    return 0;
}