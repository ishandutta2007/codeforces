#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
struct ban
{
    int i;
    int m, r;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.r > b.r)
        return true;
    if (a.r < b.r)
        return false;
    return a.m < b.m;
}
bool so(const ban& a, const ban& b)
{
    return a.m < b.m;
}

int n, q, k;
ban a[N];

long long p[N];

void solv()
{
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d%d", &a[i].m, &a[i].r);
    }
    sort(a + 1, a + n + 1);
    multiset<int> s;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (s.size() < k)
        {
            p[i] += a[i].m;
            s.insert(a[i].m);
        }
        else
        {
            if (a[i].m > *s.begin())
            {
                p[i] -= *s.begin();
                p[i] += a[i].m;
                s.erase(s.begin());
                s.insert(a[i].m);
            }
        }
    }
    long long ans = -1;
    int ansi;
    for (int i = 1; i <= n; ++i)
    {
        if (i >= k && i + (q - k) <= n)
        {
            if (p[i] > ans)
            {
                ans = p[i];
                ansi = i;
            }
        }
    }
    sort(a + 1, a + ansi + 1, so);
    for (int i = ansi; i >= ansi - k + 1; --i)
        printf("%d ", a[i].i);
    for (int i = ansi + 1; i <= ansi + (q - k); ++i)
        printf("%d ", a[i].i);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}