#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
 
const int maxn = 1e6 + 9;
vector<pii> g[maxn];
int cnt[maxn];
int x[maxn];
bool used[maxn];
int n;
int st[maxn];
int st1[maxn];
int pt[maxn];
 
void dfs(int v)
{
    used[v] = 1;
    for (pii to : g[v])
    {
        if (!used[to.ff])
            dfs(to.ff);
    }
}
 
bool check(int len)
{
    vector<int> cur;
    int mask = (1ll << len) - 1;
    for (int i = 0; i < n; i++)
    {
        g[i].resize(0);
        g[i].shrink_to_fit();
        cur.pb(x[i] & mask);
        cnt[i] = 0;
    }
    uniq(cur);
    for (int i = 0; i < n; i += 2)
    {
        int v1 = lower_bound(all(cur), (x[i] & mask)) - cur.begin();
        int v2 = lower_bound(all(cur), (x[i + 1] & mask)) - cur.begin();
//        if (v1 == v2)
//            g[v1].pb(v2, i);
//        else
//        {
            g[v1].pb(v2, i);
            g[v2].pb(v1, i + 1);
//        }
        cnt[v1]++;
        cnt[v2]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] % 2 == 1)
            return 0;
    }
    for (int i = 0; i < n; i++)
        used[i] = 0;
    dfs(0);
    for (int i = 0; i < (int)cur.size(); i++)
    {
        if (!used[i])
            return 0;
    }
    return 1;
}
 
void build()
{
//    for (int i = 0; i < n; i++)
//    {
//        if (g[i].empty())
//            continue;
//        cout << i << ":\n";
//        for (pii to : g[i])
//            cout << to.ff << " " << to.ss << "\n";
//    }
    for (int i = 0; i < n; i++)
        used[i] = 0;
    st[0] = 0;
    int sz = 1;
    vector<int> ans;
    while (sz)
    {
//        for (int i = 0; i < sz; i++)
//            cout << st[i] << " ";
//        cout << "\n";
        int v = st[sz - 1];
        while (pt[v] < (int)g[v].size() && used[g[v][pt[v]].ss / 2])
            pt[v]++;
        if (pt[v] == (int)g[v].size())
        {
            if (sz != 1)
                ans.pb(st1[sz - 1]);
            sz--;
            continue;
        }
        pii cur = g[v][pt[v]];
        used[cur.ss / 2] = 1;
        st[sz] = cur.ff;
        st1[sz] = cur.ss;
        sz++;
        pt[v]++;
    }
    for (int e : ans)
    {
        if (e % 2 == 0)
            e++;
        else
            e--;
        cout << e + 1 << " ";
        if (e % 2 == 0)
            e++;
        else
            e--;
        cout << e + 1 << " ";
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int left = 0;
    int right = 21;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (check(mid))
            left = mid;
        else
            right = mid;
    }
    cout << left << "\n";
    check(left);
    build();
}