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

int n, k;
int a[N];

int yans;

int ans[N];
vector<int> u[N];

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = 0;
        u[i].clear();
        a[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        u[x].push_back(i);
        ++a[i];
    }

    vector<int> v;

    for (int x = 1; x <= n; ++x)
    {
        while (sz(u[x]) > k)
            u[x].pop_back();
        for (int j = 0; j < sz(u[x]); ++j)
            v.push_back(u[x][j]);
    }

    while (sz(v) % k != 0)
        v.pop_back();

    for (int i = 1; i <= k; ++i)
    {
        for (int j = i - 1; j < sz(v); j += k)
        {
            ans[v[j]] = i;
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