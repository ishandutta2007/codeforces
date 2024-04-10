#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;
struct ban
{
    int i;
    int s, d;
};
bool operator<(const ban& a, const ban& b)
{
    int ua, ub;
    if (a.d < 0)
        ua = -1;
    else
        ua = 1;
    if (b.d < 0)
        ub = -1;
    else
        ub = 1;
    if (ua < ub)
        return true;
    if (ua > ub)
        return false;
    if (ua == 1)
        return m_p(a.s, -a.i) < m_p(b.s, -b.i);
    else
        return m_p(a.s, -a.i) > m_p(b.s, -b.i);
}

int n;
ban a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d%d", &a[i].s, &a[i].d);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        pair<int, int> l = min(m_p(a[i].s, -a[i].i), m_p(a[i].s + a[i].d, -a[i].i));
        pair<int, int> r = max(m_p(a[i].s, -a[i].i), m_p(a[i].s + a[i].d, -a[i].i));
        for (int j = 1; j <= n; ++j)
        {
            if (l < m_p(a[j].s, -a[j].i) && m_p(a[j].s, -a[j].i) < r)
                ++ans;
        }
        a[i].s += a[i].d;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}