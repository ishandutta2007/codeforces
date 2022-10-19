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

int n, m;
vector<int> u[N];
vector<int> v[N];

int ans[N];

void solv()
{
    cin >> n >> m;
    for (int x = 1; x <= n; ++x)
        u[x].clear();
    for (int i = 1; i <= m; ++i)
    {
        v[i].clear();
        ans[i] = 0;
    }
    for (int i = 1; i <= m; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            u[x].push_back(i);
            v[i].push_back(x);
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        if (sz(u[x]) > (m + 1) / 2)
        {
            int q = 0;
            for (int i = 0; i < sz(u[x]); ++i)
            {
                if (sz(v[u[x][i]]) == 1)
                    ++q;
            }
            if (q > (m + 1) / 2)
            {
                cout << "NO\n";
                return;
            }
            q = (m + 1) / 2;
            for (int i = 0; i < sz(u[x]); ++i)
            {
                if (sz(v[u[x][i]]) == 1)
                {
                    ans[u[x][i]] = x;
                    --q;
                }
            }
            for (int i = 0; i < sz(u[x]); ++i)
            {
                if (ans[u[x][i]])
                    continue;
                if (q == 0)
                    break;
                ans[u[x][i]] = x;
                --q;
            }
            for (int i = 1; i <= m; ++i)
            {
                if (ans[i])
                    continue;
                for (int j = 0; j < sz(v[i]); ++j)
                {
                    if (v[i][j] == x)
                        continue;
                    ans[i] = v[i][j];
                    break;
                }
            }

            cout << "YES\n";
            for (int i = 1; i <= m; ++i)
                cout << ans[i] << ' ';
            cout << "\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= m; ++i)
        cout << v[i][0] << ' ';
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
    //scanf("%d", &tt);
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}