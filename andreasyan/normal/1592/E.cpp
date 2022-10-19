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
const int N = 4000016, m = 20;

int n;
int a[N];

int p[N];
int p1[N];

int q[N];

int u[N];
int uu[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;

    int s = 0;
    for (int j = m - 1; j >= 0; --j)
    {
        p[0] = 0;
        for (int i = 1; i <= n; ++i)
            p[i] = (p[i - 1] ^ (a[i] & s));

        if (j == 2)
            cout << "";

        p1[0] = 0;
        for (int i = 1; i <= n; ++i)
            p1[i] = (p1[i - 1] + !!(a[i] & (1 << j)));
        for (int i = 1; i <= n; ++i)
            p1[i] -= i;
        int minu = 0;
        for (int i = 1; i <= n; ++i)
            minu = min(minu, p1[i]);
        for (int i = 0; i <= n; ++i)
            p1[i] -= minu;
        for (int i = 1; i <= n; i += 2)
            p1[i] += 2 * n + 1;

        memset(q, 0, sizeof q);
        for (int i = 0; i <= n; ++i)
            q[p[i]]++;
        for (int i = 1; i < N; ++i)
            q[i] += q[i - 1];
        for (int i = 0; i <= n; ++i)
            u[--q[p[i]]] = i;

        memset(q, 0, sizeof q);
        for (int i = 0; i <= n; ++i)
            q[p1[i]]++;
        for (int i = 1; i < N; ++i)
            q[i] += q[i - 1];
        for (int i = n; i >= 0; --i)
            uu[--q[p1[u[i]]]] = u[i];

        int l = uu[0], r = uu[0];
        for (int i = 0; i < n; ++i)
        {
            assert(m_p(p1[uu[i]], p[uu[i]]) <= m_p(p1[uu[i + 1]], p[uu[i + 1]]));
            if (m_p(p1[uu[i]], p[uu[i]]) == m_p(p1[uu[i + 1]], p[uu[i + 1]]))
            {
                l = min(l, uu[i + 1]);
                r = max(r, uu[i + 1]);
            }
            else
            {
                ans = max(ans, r - l);
                l = r = uu[i + 1];
            }
        }
        ans = max(ans, r - l);

        s |= (1 << j);
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