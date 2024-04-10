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
const int N = 3003;

int n;
int f[N], s[N];

int p[N];
int minu[N], maxu[N];

int fin(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fin(p[x]);
}

ll sum;

void solv()
{
    cin >> n;
    for (int i = 1; i <= n * 2; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (!f[x])
            f[x] = y - n;
        else
            s[x] = y - n;
    }

    for (int x = 1; x <= n; ++x)
    {
        if (f[x] > s[x])
            swap(f[x], s[x]);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            p[j] = j;
            minu[j] = maxu[j] = j;
        }

        for (int j = i; j <= n; ++j)
        {
            if (fin(f[j]) == fin(s[j]))
            {
                int x = fin(f[j]);
                sum += minu[x] * (n - maxu[x] + 1);
            }
            else
            {
                int x = fin(f[j]);
                int y = fin(s[j]);
                sum += minu[x] * (n - maxu[x] + 1);
                sum += minu[y] * (n - maxu[y] + 1);

                if ((rnd() % 2))
                    swap(x, y);
                minu[y] = min(minu[y], minu[x]);
                maxu[y] = max(maxu[y], maxu[x]);
                p[x] = y;
                sum -= minu[y] * (n - maxu[y] + 1);
            }

            ans += sum;
        }
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