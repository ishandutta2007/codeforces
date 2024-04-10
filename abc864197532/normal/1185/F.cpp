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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tmp;
    cin >> n >> m;
    vector <int> a(512, 0), al(512, 0);
    vector <pii> b[512];
    fop (i,0,n) {
        int st = 0;
        cin >> k;
        while (k--) cin >> tmp, st |= 1 << tmp - 1;
        a[st]++;
    }
    fop (i,0,m) {
        int cost, st = 0;
        cin >> cost >> k;
        while (k--) cin >> tmp, st |= 1 << tmp - 1;
        b[st].eb(cost, i);
    }
    fop (s,0,512) {
        fop (s1,0,512) if (!(~s & s1)) al[s] += a[s1];
        sort(all(b[s]));
    }
    pii ans = {-1, 0}, id = {-1, -1};
    fop (s1,0,512) fop (s2,0,512) {
        if (b[s1].empty() || b[s2].empty()) continue;
        pii re, id2;
        if (s1 == s2) {
            if (b[s1].size() >= 2) {
                re = mp(al[s1], -b[s1][0].X - b[s2][1].X);
                id2 = mp(b[s1][0].Y, b[s2][1].Y);
            } else {
                continue;
            }
        } else {
            re = mp(al[s1 | s2], -b[s1][0].X - b[s2][0].X);
            id2 = mp(b[s1][0].Y, b[s2][0].Y);
        }
        if (ans < re) {
            ans = re;
            id = id2;
        }
    }
    cout << id.X + 1 << ' ' << id.Y + 1 << endl;
}