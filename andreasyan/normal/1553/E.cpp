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
const int N = 300005;

int n, m;
int a[N];
int u[N];
int h[N];
bool c[N];

int qq[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        u[a[i]] = i;

    for (int i = 0; i < n; ++i)
        qq[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        qq[(u[i] - i + n) % n]++;
    }

    vector<int> ans;
    for (int k = 0; k < n; ++k)
    {
        if (qq[k] < n / 10)
            continue;
        for (int i = 1; i <= n; ++i)
        {
            h[i] = (u[i] - 1 - k + n) % n + 1;
            c[i] = false;
        }
        int q = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (c[i])
                continue;
            ++q;
            int x = i;
            while (1)
            {
                if (c[x])
                    break;
                c[x] = true;
                x = h[x];
            }
        }

        if (n - q <= m)
            ans.push_back(k);
    }

    cout << sz(ans) << ' ';
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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