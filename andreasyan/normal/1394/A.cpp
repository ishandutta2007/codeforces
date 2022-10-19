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

int n, d, m;
int a[N];

void solv()
{
    scanf("%d%d%d", &n, &d, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    vector<int> v1, v2;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] <= m)
            v1.push_back(a[i]);
        else
            v2.push_back(a[i]);
    }
    sort(all(v1));
    sort(all(v2));

    vector<ll> s1;
    s1.assign(sz(v1) + 5, 0);
    for (int i = sz(v1) - 1; i >= 0; --i)
        s1[i] = s1[i + 1] + v1[i];

    vector<ll> s2;
    s2.assign(sz(v2) + 5, 0);
    for (int i = sz(v2) - 1; i >= 0; --i)
        s2[i] = s2[i + 1] + v2[i];

    ll ans = 0;
    for (int q = 0; q <= sz(v1); ++q)
    {
        ll yans = 0;
        if (q)
            yans += s1[sz(v1) - q];

        int qq = (n - q) / (d + 1) + !!((n - q) % (d + 1));

        if (qq > sz(v2))
            continue;

        if (qq)
            yans += s2[sz(v2) - qq];

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
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}