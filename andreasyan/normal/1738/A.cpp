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

int n;
int a[N], b[N];

ll solvv(vector<int> v[2], int z)
{
    ll ans = 0;
    while (1)
    {
        if (v[0].empty() && v[1].empty())
            return ans;
        if (v[0].empty())
        {
            ans += v[1].back();
            v[1].pop_back();
        }
        else if (v[1].empty())
        {
            ans += v[0].back();
            v[0].pop_back();
        }
        else
        {
            ans += v[z].back() * 2;
            v[z].pop_back();
            z ^= 1;
        }
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    vector<int> v[2];
    for (int i = 1; i <= n; ++i)
        v[a[i]].push_back(b[i]);
    sort(all(v[0]));
    sort(all(v[1]));
    ll ans = solvv(v, 0);

    for (int i = 1; i <= n; ++i)
        v[a[i]].push_back(b[i]);
    sort(all(v[0]));
    sort(all(v[1]));
    ans = max(ans, solvv(v, 1));

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