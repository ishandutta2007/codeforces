#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

int MOD =  998244353;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));


const int LIM = 400005;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

/*
struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

int n, m;

vector<pair<int, int>> close(pair<int, int> a)
{
    vector<pair<int, int>> ans;
    int x = a.first; int y = a.second;
    if (x>0) ans.push_back(mp(x-1, y));
    if (x+1<n) ans.push_back(mp(x+1, y));
    if (y>0) ans.push_back(mp(x, y-1));
    if (y+1<m) ans.push_back(mp(x, y+1));
    return ans;
}

void solve()
{
    cin>>n>>m;

    vector<string> s(n);
    for (int i = 0; i<n; i++) cin>>s[i];

    vector<vector<int>> cnt_free(n, vector<int>(m));

    set<pair<int, pair<int, int>>> guys;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (s[i][j]=='.')
        {
            bool available = false;
            auto who = close(mp(i, j));
            for (auto it: who)
            {
                if (s[it.first][it.second]=='.') cnt_free[i][j]++;
                if (s[it.first][it.second]=='L') available = true;
            }
            if (available) guys.insert(mp(cnt_free[i][j], mp(i, j)));
        }

    vector<vector<bool>> erased(n, vector<bool>(m, true));

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++) if (s[i][j]=='.') erased[i][j] = false;

    while (!guys.empty())
    {
        auto it = *guys.begin();
        if (it.first>=2) break;

        guys.erase(it);

        auto cell = it.second;
        erased[cell.first][cell.second] = true;
        s[cell.first][cell.second] = '+';
        //cout<<cell.first<<' '<<cell.second<<endl;

        auto who = close(cell);

        for (auto guy: who)
        {
            if (erased[guy.first][guy.second]) continue;
            if (guys.count(mp(cnt_free[guy.first][guy.second], guy)))
            {
                guys.erase(mp(cnt_free[guy.first][guy.second], guy));
            }
            cnt_free[guy.first][guy.second]--;
            guys.insert(mp(cnt_free[guy.first][guy.second], guy));
        }

    }

    for (auto it: s) cout<<it<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}
/*
1
1 9
....L..#.
 */