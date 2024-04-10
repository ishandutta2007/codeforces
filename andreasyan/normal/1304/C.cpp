#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102;
struct ban
{
    int t;
    pair<int, int> h;
};
bool operator<(const ban& a, const ban& b)
{
    return a.t < b.t;
}

int n, m;
ban a[N];

pair<int, int> hat(pair<int, int> a, pair<int, int> b)
{
    if (a.first > a.second)
        return a;
    if (b.first > b.second)
        return b;
    if (a.second > b.second)
        swap(a, b);
    if (a.second < b.first)
        return m_p(1, 0);
    if (a.first < b.first)
        return m_p(b.first, a.second);
    return a;
}

bool solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i].t, &a[i].h.first, &a[i].h.second);
    sort(a + 1, a + n + 1);
    a[0].t = 0;
    a[0].h = m_p(m, m);
    for (int i = 1; i <= n; ++i)
    {
        a[i].h = hat(a[i].h, m_p(a[i - 1].h.first - (a[i].t - a[i - 1].t), a[i - 1].h.second + (a[i].t - a[i - 1].t)));
        if (a[i].h.first > a[i].h.second)
            return false;
    }
    return true;
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}