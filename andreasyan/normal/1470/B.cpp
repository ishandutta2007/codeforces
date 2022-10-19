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
const int N = 1000006;

int u[N];
int t[N];

void pre()
{
    u[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        u[i] = i;
        if (i * 1LL * i >= N)
            continue;
        for (int j = i * i; j < N; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }

    for (int i = 1; i < N; ++i)
    {
        t[i] = 1;
        int x = i;
        int q = 0;
        int z = 0;
        while (x > 1)
        {
            if (u[x] == z)
                ++q;
            else
            {
                if (q % 2 == 1)
                    t[i] *= z;
                z = u[x];
                q = 1;
            }
            x /= u[x];
        }
        if (q % 2 == 1)
            t[i] *= z;
    }
}

int n;
int a[N];
int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        q[t[a[i]]]++;

    int ans0 = 0;
    for (int i = 1; i <= n; ++i)
        ans0 = max(ans0, q[t[a[i]]]);

    int ans1 = ans0;
    int yans = q[1];
    for (int i = 1; i <= n; ++i)
    {
        if (t[a[i]] == 1)
            continue;
        if (q[t[a[i]]] % 2 == 0)
        {
            yans += q[t[a[i]]];
            q[t[a[i]]] = 0;
        }
    }
    ans1 = max(ans1, yans);

    for (int i = 1; i <= n; ++i)
        q[t[a[i]]] = 0;

    int qq;
    cin >> qq;
    while (qq--)
    {
        ll w;
        cin >> w;
        if (w == 0)
            cout << ans0 << "\n";
        else
            cout << ans1 << "\n";
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}