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
char a[N];

int p[2][2][N];

bool stg(int l, int r)
{
    if (!(p[0][1][r] - p[0][1][l - 1]) && !(p[1][0][r] - p[1][0][l - 1]))
        return true;
    if (!(p[0][0][r] - p[0][0][l - 1]) && !(p[1][1][r] - p[1][1][l - 1]))
        return true;
    return false;
}

void solv()
{
    cin >> (a + 1);
    for (n = 1; a[n]; ++n){}
    --n;

    for (int z = 0; z < 2; ++z)
    {
        for (int i = 1; i <= n; ++i)
        {
            p[z][0][i] = p[z][0][i - 1];
            p[z][1][i] = p[z][1][i - 1];
            if (i % 2 != z)
            {
                continue;
            }
            if (a[i] != '?')
            {
                p[z][a[i] - '0'][i]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i;
        int u;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (stg(m, i))
            {
                u = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        ans += (i - u + 1);
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}