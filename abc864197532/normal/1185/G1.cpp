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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
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

const int mod = 1e9 + 7, x = 864197532, N = 1000001, logN = 17;

int solve(vector <int> a, int pre, int k, int n) {
    if (k == n) {
        return 1;
    }
    int ans = 0;
    fop (i,0,3) if (a[i] && i != pre) {
        a[i]--;
        ans += solve(a, i, k + 1, n);
        a[i]++;
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector <pii> v(n);
    fop (i,0,n) cin >> v[i].X >> v[i].Y;
    lli ans = 0, cur = 1;
    lli frac[n + 1];
    frac[0] = 1;
    fop (i,1,n + 1) frac[i] = frac[i - 1] * i % mod;
    vector <int> pre(10000, 0);
    fop (s,0,1 << n) {
        int all = 0;
        fop (i,0,n) if (s & (1 << i)) all += v[i].X;
        if (all != t) continue;
        vector <int> cnt(3, 0);
        fop (i,0,n) if (s & (1 << i)) cnt[v[i].Y - 1]++;
        ans = (ans + (frac[cnt[0]] * frac[cnt[1]] % mod * frac[cnt[2]] % mod * solve({cnt[0], cnt[1], cnt[2]}, -1, 0, cnt[0] + cnt[1] + cnt[2]) % mod)) % mod;
    }
    cout << ans << endl;
}