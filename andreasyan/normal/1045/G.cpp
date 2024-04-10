#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, K = 44, INF = 1003000009;
struct ban
{
    int x, r, q;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, k;
ban a[N];

int t[N];
void ubd(int n, int x, int y)
{
    ++x;
    while (x <= n)
    {
        t[x] += y;
        x += (x & (-x));
    }
}

int qry(int l, int r)
{
    if (l > r)
        return 0;
    ++l;
    ++r;
    int ans = 0;
    while (r)
    {
        ans += t[r];
        r -= (r & (-r));
    }
    --l;
    while (l)
    {
        ans -= t[l];
        l -= (l & (-l));
    }
    return ans;
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q);
    sort(a + 1, a + n + 1);
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(m_p(a[i].q, a[i].x));
    }
    sort(v.begin(), v.end());
    priority_queue<pair<int, pair<int, int> > > q;
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (!q.empty() && -q.top().first < a[i].x)
        {
            ubd(v.size(), lower_bound(v.begin(), v.end(), q.top().second) - v.begin(), -1);
            q.pop();
        }
        for (int j = max(0, a[i].q - k); j <= a[i].q + k; ++j)
        {
            ans += qry(lower_bound(v.begin(), v.end(), m_p(j, a[i].x - a[i].r)) - v.begin(), lower_bound(v.begin(), v.end(), m_p(j, INF)) - v.begin() - 1);
        }
        ubd(v.size(), lower_bound(v.begin(), v.end(), m_p(a[i].q, a[i].x)) - v.begin(), 1);
        q.push(m_p(-(a[i].x + a[i].r), m_p(a[i].q, a[i].x)));
    }
    printf("%I64d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}