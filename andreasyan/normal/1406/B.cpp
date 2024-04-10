#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const ll INF = 1000000009000000009;

void solv()
{
    int n;
    scanf("%d", &n);
    vector<int> d, b;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x >= 0)
            d.push_back(x);
        else
            b.push_back(x);
    }
    sort(all(d));
    sort(all(b));
    ll ans = -INF;
    for (int qd = 0; qd <= min(sz(d), 5); ++qd)
    {
        int qb = 5 - qd;
        if (qb > sz(b))
            continue;
        ll yans = 1;
        for (int i = 0; i < qd; ++i)
            yans *= d[i];
        for (int i = 0; i < qb; ++i)
            yans *= b[i];
        ans = max(ans, yans);
    }
    reverse(all(b));
    for (int qd = 0; qd <= min(sz(d), 5); ++qd)
    {
        int qb = 5 - qd;
        if (qb > sz(b))
            continue;
        ll yans = 1;
        for (int i = 0; i < qd; ++i)
            yans *= d[i];
        for (int i = 0; i < qb; ++i)
            yans *= b[i];
        ans = max(ans, yans);
    }
    reverse(all(d));
    for (int qd = 0; qd <= min(sz(d), 5); ++qd)
    {
        int qb = 5 - qd;
        if (qb > sz(b))
            continue;
        ll yans = 1;
        for (int i = 0; i < qd; ++i)
            yans *= d[i];
        for (int i = 0; i < qb; ++i)
            yans *= b[i];
        ans = max(ans, yans);
    }
    reverse(all(b));
    for (int qd = 0; qd <= min(sz(d), 5); ++qd)
    {
        int qb = 5 - qd;
        if (qb > sz(b))
            continue;
        ll yans = 1;
        for (int i = 0; i < qd; ++i)
            yans *= d[i];
        for (int i = 0; i < qb; ++i)
            yans *= b[i];
        ans = max(ans, yans);
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}