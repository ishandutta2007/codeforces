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
const int N = 10004;
 
map<vector<int>, int> mp;
int qry(int t, int i, int j, int x)
{
    if (mp.find({t, i, j, x}) != mp.end())
        return mp[{t, i, j, x}];
    cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
    int ans;
    cin >> ans;
    return mp[{t, i, j, x}] = ans;
}
//
 
int n;
int ans[N];
 
vector<int> v[N];
 
void solv()
{
    cin >> n;
 
    mp.clear();
    for (int i = 1; i <= n; ++i)
        v[i].clear();
    for (int i = 1; i <= n; ++i)
        ans[i] = 0;
 
    int u = -1;
    for (int i = 1; i < n; ++i)
    {
        if (qry(2, i, i + 1, 1) == 1)
        {
            u = i;
            break;
        }
    }
    if (u == -1)
        u = n;
 
    ans[0] = -1;
    ans[n + 1] = -1;
    ans[u] = 1;
 
    for (int i = 1; i < u - 1; ++i)
    {
        v[qry(2, i, i + 1, 1)].push_back(i);
    }
    for (int i = u + 1; i < n; ++i)
    {
        v[qry(2, i, i + 1, 1)].push_back(i);
    }
 
    for (int x = 2; x <= n; ++x)
    {
        if (sz(v[x]) == 2)
        {
            ans[v[x].back()] = x;
            continue;
        }
        if (sz(v[x]) == 1)
        {
            int i = v[x][0];
            if (!ans[i - 1])
            {
                ans[i + 1] = x;
                continue;
            }
            if (!ans[i + 2])
            {
                ans[i] = x;
                continue;
            }
            int r = rnd() % 2;
            ans[i + r] = qry(1, u, i + r, n - 1);
            if (ans[i + r] != x)
                ans[i + 1 - r] = x;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!ans[i])
            ans[i] = qry(1, u, i, n - 1);
    }
 
    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
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