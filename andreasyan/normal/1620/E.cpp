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
const int N = 500006;

int n;
int a[N];

vector<pair<int, int> > v[N];

int u[N];

int ans[N];

void solv()
{
    int qq;
    cin >> qq;

    int n = 0;
    while (qq--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int x;
            cin >> x;
            a[++n] = x;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            v[n].push_back(m_p(x, y));
        }
    }

    for (int i = 0; i < N; ++i)
        u[i] = i;

    for (int i = n; i >= 1; --i)
    {
        for (int j = sz(v[i]) - 1; j >= 0; --j)
        {
            u[v[i][j].fi] = u[v[i][j].se];
        }
        ans[i] = u[a[i]];
    }

    for (int i = 1; i <= n; ++i)
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}