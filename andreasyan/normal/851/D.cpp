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
const int N = 2000006;

int n, x, y;
int q[N];

ll pq[N];
ll p[N];

void solv()
{
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++q[x];
    }

    for (int i = 1; i < N; ++i)
    {
        pq[i] = pq[i - 1] + q[i];
        p[i] = p[i - 1] + q[i] * 1LL * i;
    }

    ll ans = n * 1LL * x;
    for (int d = 2; d < N; ++d)
    {
        ll yans = 0;
        for (int i = d; i < N; i += d)
        {
            int u = min(x / y, d - 1);
            yans += ((pq[i] - pq[i - u - 1]) * 1LL * i - (p[i] - p[i - u - 1])) * 1LL * y;
            yans += (pq[i - u - 1] - pq[i - d]) * 1LL * x;
        }
        ans = min(ans, yans);
    }

    cout << ans << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}