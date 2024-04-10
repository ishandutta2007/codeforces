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
const int N = 33;

int m, n;

int qry(int x)
{
    cout << x << endl;
    int ans;
    cin >> ans;

    if (ans == 0)
    {
        exit(0);
    }

    return ans;
}

int p[N];

void solv()
{
    cin >> m >> n;

    for (int i = 1; i <= n; ++i)
    {
        if (qry(i) == 1)
            p[i] = 1;
        else
            p[i] = 0;
    }

    int i = 0;
    int l = 2, r = m;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int u = qry(m);
        ++i;
        if (i == n + 1)
            i = 1;
        if (p[i])
        {
            if (u == -1)
                r = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (u == 1)
                r = m - 1;
            else
                l = m + 1;
        }
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