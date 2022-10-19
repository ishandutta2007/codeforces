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
const int N = 200005;

int n, qq;
int a[N];

ll p[N];

void solv()
{
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    vector<pair<ll, int> > v;
    for (int i = 1; i <= n; ++i)
        v.push_back(m_p(p[i], i));
    sort(all(v));
    vector<int> s(sz(v) + 1);
    s[sz(v)] = N;
    for (int i = sz(v) - 1; i >= 0; --i)
        s[i] = min(s[i + 1], v[i].se);

    while (qq--)
    {
        int x;
        scanf("%d", &x);

        int i = lower_bound(all(v), m_p(x * 1LL, 0)) - v.begin();

        if (s[i] == N)
        {
            if (p[n] <= 0)
            {
                printf("-1 ");
                continue;
            }

            ll ans = (x / p[n]) * n + n;

            int l = 1, r = (x / p[n]);
            while (l <= r)
            {
                int u = (l + r) / 2;
                ll yans = (u * 1LL * n);
                ll xx = x;
                xx -= u * 1LL * p[n];
                int i = lower_bound(all(v), m_p(xx, 0)) - v.begin();
                if (s[i] != N)
                {
                    ans = u * 1LL * n + s[i];
                    r = u - 1;
                }
                else
                    l = u + 1;
            }
            printf("%lld ", ans - 1);
        }
        else
            printf("%d ", s[i] - 1);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}