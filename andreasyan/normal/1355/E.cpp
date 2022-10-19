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

int n;
int A, R, M;
int a[N];

void kar()
{
    scanf("%d", &n);
    scanf("%d%d%d", &A, &R, &M);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

ll p[N];

ll stg(int x)
{
    ll s = 0;
    ll ss = 0;
    for (int i = 1; i <= n; ++i)
    {
        ss += abs(a[i] - x);
        s += a[i];
    }
    ll ans = 0;
    if (s > n * 1LL * x)
    {
        ans += (s - n * 1LL * x) * R;
    }
    else
    {
        ans += (n * 1LL * x - s) * A;
    }
    ans += (ss - abs(s - n * 1LL * x)) / 2 * M;
    return ans;
}

ll solv()
{
    M = min(M, A + R);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    int l = 0, r = 1000000000;
    while ((r - l) > 5)
    {
        int m = (l + r) / 2;
        if (stg(m) > stg(m + 1))
            l = m;
        else
            r = m + 1;
    }
    ll ans = INF;
    for (int i = l; i <= r; ++i)
        ans = min(ans, stg(i));
    return ans;
}

ll solv0()
{
    vector<int> v;
    int minu = a[1];
    int maxu = a[1];
    for (int i = 1; i <= n; ++i)
    {
        minu = min(minu, a[i]);
        maxu = max(maxu, a[i]);
        v.push_back(a[i]);
    }
    map<vector<int>, ll> d;
    priority_queue<pair<ll, vector<int> > > q;
    q.push(m_p(0, v));
    ll ans = INF;
    while (1)
    {
        ll yd;
        do
        {
            v = q.top().se;
            yd = q.top().fi;
            q.pop();
        } while (d.find(v) != d.end());
        d[v] = -yd;
        bool z = true;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i] != v[0])
            {
                z = false;
                break;
            }
        }
        if (z)
            return d[v];
        for (int i = 0; i < v.size(); ++i)
        {
            vector<int> u = v;
            ++u[i];
            if (minu <= u[i] && u[i] <= maxu)
            {
                q.push(m_p(-(d[v] + A), u));
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            vector<int> u = v;
            --u[i];
            if (minu <= u[i] && u[i] <= maxu)
            {
                q.push(m_p(-(d[v] + R), u));
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            for (int j = 0; j < v.size(); ++j)
            {
                vector<int> u = v;
                --u[i];
                ++u[j];
                if (minu <= u[i] && u[j] <= maxu)
                {
                    q.push(m_p(-(d[v] + M), u));
                }
            }
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    kar();
    printf("%lld\n", solv());
    return 0;
    while (1)
    {
        n = 6;
        A = rnf() % 5;
        R = rnf() % 5;
        M = rnf() % 5;
        for (int i = 1; i <= n; ++i)
            a[i] = rnf() % 5;
        if (solv() != solv0())
        {
            printf("WA\n");
            printf("%d\n", n);
            printf("%d %d %d\n", A, R, M);
            for (int i = 1; i <= n; ++i)
                printf("%d ", a[i]);
            printf("\n");
            return 0;
        }
        else
        {
            printf("OK\n");
        }
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}