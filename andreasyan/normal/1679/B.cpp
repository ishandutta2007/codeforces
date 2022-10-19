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

int n, q;
int a[N], t[N];

void solv()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i];

    int aa = -1;
    int tt = -1;
    for (int i = 1; i <= q; ++i)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x, y;
            cin >> x >> y;

            if (t[x] < tt)
            {
                a[x] = aa;
            }

            s -= a[x];

            t[x] = i;
            a[x] = y;

            s += a[x];
        }
        else
        {
            cin >> aa;
            tt = i;

            s = n * 1LL * aa;
        }

        cout << s << "\n";
    }
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