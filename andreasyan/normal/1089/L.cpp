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
const int N = 100005;

int n, k;
int a[N], b[N];

vector<int> v[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        v[a[i]].push_back(b[i]);

    vector<int> vv;
    int q = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (v[i].empty())
        {
            ++q;
            continue;
        }

        sort(all(v[i]));
        v[i].pop_back();
        for (int j = 0; j < sz(v[i]); ++j)
            vv.push_back(v[i][j]);
    }

    sort(all(vv));
    ll ans = 0;
    for (int i = 0; i < q; ++i)
        ans += vv[i];

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