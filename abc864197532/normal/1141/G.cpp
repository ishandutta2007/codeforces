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

// AC automaton will help me get AC!
struct AC {
    vector <vector <int>> ch;
    vector <int> cnt, f;
    AC () {extend();}
    void extend() {
        ch.pb(vector <int>(26, 0));
        cnt.pb(0);
    }
    int next(int u, int v) {
        if (!ch[u][v]) {
            ch[u][v] = ch.size();
            extend();
        }
        return ch[u][v];
    }
    void insert(string &s) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - 'a');
        }
        cnt[now]++;
    }
    void build_fail() {
        f.assign(ch.size(), 0);
        queue <int> q;
        for (int i = 0; i < 26; ++i) if (ch[0][i]) q.push(ch[0][i]);
        while (q.size()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 26; ++i) if (ch[v][i]) {
                    int k = f[v];
                    while (k && !ch[k][i]) k = f[k];
                    if (ch[k][i]) k = ch[k][i];
                    f[ch[v][i]] = k;
                    cnt[ch[v][i]] += cnt[k];
                    q.push(ch[v][i]);
                }
        }
    }
    int match(string &s) {
        int k = 0, ans = 0;
        for (char c : s) {
            while (k && !ch[k][c - 'a']) k = f[k];
            if (ch[k][c - 'a']) k = ch[k][c - 'a'];
            ans += cnt[k];
        }
        return ans;
    }
};

const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 17;

vector <pii> adj[N];
vector <int> in;
int t = 0;

void dfs(int v, int pa) {
    in[v] = t++;
    for (pii A : adj[v]) if (A.X != pa) {
        dfs(A.X, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, u, v;
    cin >> n >> k;
    in.resize(n);
    fop (i,0,n - 1) {
        cin >> u >> v, u--, v--;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {
        return adj[i].size() > adj[j].size();
    });
    vector <bool> bad(n, false);
    fop (i,0,k) bad[p[i]] = true;
    int c = adj[p[k]].size();
    dfs(0, -1);
    vector <bool> colored(c, false);
    vector <int> ans(n - 1, -1);
    sort(all(p), [&](int i, int j) {
        return in[i] < in[j];
    });
    fop (i,0,n) {
        int v = p[i];
        if (bad[v]) continue;
        for (auto A : adj[v]) {
            if (~ans[A.Y]) colored[ans[A.Y]] = true;
        }
        int cur = 0;
        for (auto A : adj[v]) if (!~ans[A.Y]) {
            while (colored[cur]) cur++;
            ans[A.Y] = cur;
            colored[cur] = true;
        }
        for (auto A : adj[v]) {
            colored[ans[A.Y]] = false;
        }
    }
    fop (i,0,n - 1) {
        if (ans[i] == -1) ans[i] = 0;
        ans[i]++;
    }
    cout << c << endl;
    printv(ans);
}