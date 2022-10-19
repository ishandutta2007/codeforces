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
int a[N];

vector<int> u[N];

int ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        u[i].clear();
    for (int i = 1; i <= n; ++i)
        u[a[i]].push_back(i);

    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++i)
        v.push_back(m_p(sz(u[i]), i));

    sort(all(v));
    reverse(all(v));

    while (1)
    {
        while (!v.empty() && v.back().fi == 0)
            v.pop_back();
        if (v.empty())
            break;

        for (int i = 0; i < sz(v); ++i)
        {
            ans[u[v[i].se].back()] = v[(i + 1) % sz(v)].se;
            u[v[i].se].pop_back();
            --v[i].fi;
        }
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}