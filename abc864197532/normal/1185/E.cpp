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

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    vector <pii> abc[26];
    fop (i,0,n) {
        cin >> s[i];
        fop (j,0,m) if (s[i][j] != '.') abc[s[i][j] - 'a'].eb(i, j);
    }
    vector <pair <pii, pii>> ans;
    bool is = false;
    vector <vector <bool>> in(n, vector <bool>(m, false));
    pii block;
    FOP (c,26,0) if (abc[c].size() || is) {
        is = true;
        if (abc[c].empty()) {
            ans.eb(block, block);
        } else {
            int mnx = 1 << 30, mxx = -1 << 30, mny = 1 << 30, mxy = -1 << 30;
            for (auto A : abc[c]) {
                mnx = min(mnx, A.X);
                mxx = max(mxx, A.X);
                mny = min(mny, A.Y);
                mxy = max(mxy, A.Y);
            }
            block = mp(mnx, mny);
            if (mnx == mxx) {
                int cnt = 0, i = mnx;
                bool is = true;
                fop (j,mny, mxy + 1) {
                    if (s[i][j] == 'a' + c || in[i][j]) cnt++;
                    in[i][j] = true;
                }
                if (cnt == mxy - mny + 1) {
                    ans.eb(mp(i, mny), mp(i, mxy));
                } else {
                    cout << "NO\n";
                    return;
                }
            } else if (mny == mxy) {
                int cnt = 0, j = mny;
                bool is = true;
                fop (i,mnx, mxx + 1) {
                    if (s[i][j] == 'a' + c || in[i][j]) cnt++;
                    in[i][j] = true;
                }
                if (cnt == mxx - mnx + 1) {
                    ans.eb(mp(mnx, j), mp(mxx, j));
                } else {
                    cout << "NO\n";
                    return;
                }
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    reverse(all(ans));
    cout << "YES\n";
    cout << ans.size() << endl;
    for (auto A : ans) cout << A.X.X + 1 << ' ' << A.X.Y + 1 << ' ' << A.Y.X + 1 << ' ' << A.Y.Y + 1 << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}