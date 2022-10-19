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
const int N = 102;

int n;
int a[N];
int b[N];

int c[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    memset(c, 0, sizeof c);

    int i = 1, j = 1;
    int u = 0;
    while (u < n)
    {
        bool za = false, zb = false;
        for (int k = 1; k <= n; ++k)
        {
            if (c[k])
                continue;
            if (a[k] == i)
                za = true;
            if (b[k] == j)
                zb = true;
        }

        if (!za)
        {
            ++i;
            continue;
        }
        if (!zb)
        {
            ++j;
            continue;
        }

        bool z = false;
        for (int k = 1; k <= n; ++k)
        {
            if (c[k])
                continue;
            if (a[k] == i && b[k] == j)
            {
                c[k] = ++u;
                z = true;
                break;
            }
        }

        if (!z)
        {
            cout << "-1\n";
            return;
        }
    }

    vector<pair<int, int> > ans;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == i)
            continue;
        for (int j = 1; j <= n; ++j)
        {
            if (c[j] == i)
            {
                ans.push_back(m_p(i, j));
                swap(c[j], c[i]);
                break;
            }
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
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