#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17;

vector <pii> adj[N];
vector <int> dis;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, u, v, idd;
    cin >> n >> m >> k;
    fop (i,0,m) {
        cin >> u >> v, u--, v--;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }
    dis.assign(n, -1);
    queue <int> q;
    q.push(0);
    dis[0] = 0;
    vector <int> id(n, -1);
    vector <vector <int>> pos;
    while (q.size()) {
        v = q.front(); q.pop();
        for (pii A : adj[v]) {
            tie(u, idd) = A;
            if (!~dis[u]) {
                q.push(u);
                id[u] = pos.size();
                pos.pb({idd});
                dis[u] = dis[v] + 1;
            } else if (dis[u] == dis[v] + 1) {
                pos[id[u]].pb(idd);
            }
        }
    }
    vector <int> cur(n - 1, 0);
    vector <string> ans;
    while (ans.size() < k) {
        string s = string(m, '0');
        fop (i,0,n - 1) s[pos[i][cur[i]]] = '1';
        ans.pb(s);
        int now = n - 2;
        while (~now) {
            cur[now]++;
            if (cur[now] == pos[now].size()) cur[now--] = 0;
            else break;
        }
        if (!~now) break;
    }
    cout << ans.size() << endl;
    for (string &s : ans) cout << s << '\n';
}