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
const int N = 2003;

int n;

int d[N][N];
bool c[N];
void qry(int r)
{
    if (c[r])
        return;
    c[r] = true;
    cout << "? " << r << endl;
    for (int i = 1; i <= n; ++i)
        cin >> d[r][i];
}

void solv()
{
    cin >> n;

    qry(1);

    vector<int> v[2];

    for (int x = 1; x <= n; ++x)
    {
        v[d[1][x] % 2].push_back(x);
    }

    if (sz(v[1]) < sz(v[0]) - 1)
        swap(v[1], v[0]);

    vector<pair<int, int> > ans;
    for (int i = 0; i < sz(v[0]); ++i)
    {
        int x = v[0][i];
        qry(x);
        for (int y = 1; y <= n; ++y)
        {
            if (d[x][y] == 1)
                ans.push_back(m_p(x, y));
        }
    }

    cout << '!' << endl;
    for (int i = 0; i < n - 1; ++i)
        cout << ans[i].fi << ' ' << ans[i].se << endl;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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