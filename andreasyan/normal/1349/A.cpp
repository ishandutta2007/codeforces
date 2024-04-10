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

int n;

int c[N];
int q[N];

vector<int> vv[N];

void solv()
{
    for (int i = 2; i < N; ++i)
    {
        if (c[i])
            continue;
        c[i] = i;
        if (i * 1LL * i >= N)
            continue;
        for (int j = i * i; j < N; j += i)
        {
            if (!c[j])
                c[j] = i;
        }
    }
    scanf("%d", &n);
    for (int ii = 0; ii < n; ++ii)
    {
        int x;
        scanf("%d", &x);
        vector<pair<int, int> > v;
        while (x > 1)
        {
            if (v.empty() || c[x] != v.back().fi)
            {
                v.push_back(m_p(c[x], 1));
            }
            else
            {
                v.back().se++;
            }
            x /= c[x];
        }
        for (int i = 0; i < v.size(); ++i)
        {
            vv[v[i].fi].push_back(v[i].se);
        }
    }
    ll ans = 1;
    for (int i = 2; i < N; ++i)
    {
        if (c[i] != i)
            continue;
        sort(vv[i].begin(), vv[i].end());
        if (vv[i].empty())
            continue;
        if (n - sz(vv[i]) >= 2)
            continue;
        if (n - sz(vv[i]) == 0)
        {
            for (int j = 0; j < vv[i][1]; ++j)
                ans *= i;
        }
        else
        {
            for (int j = 0; j < vv[i][0]; ++j)
                ans *= i;
        }
    }
    printf("%lld\n", ans);
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