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

vector <int> a;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    fop (i,0,n) cin >> a[i];
    vector <int> p(n);
    iota(all(p), 0);
    sort(all(p), [&](int i, int j) {return a[i] < a[j];});
    sort(all(a));
    vector <int> b;
    fop (i,1,n) b.pb(a[i] - a[i - 1]);
    bool is = true;
    fop (i,1,b.size() - 1) {
        if (b[i] != b[i + 1]) is = false;
    }
    if (is) {
        cout << p[0] + 1 << endl;
        return 0;
    }
    vector <int> c;
    fop (i,0,b.size()) {
        if (!i) c.pb(b[i] + b[i + 1]);
        else if (i != 1) c.pb(b[i]);
    }
    sort(all(c));
    if (c[0] == c.back()) {
        cout << p[1] + 1 << endl;
        return 0;
    }
    int ignore = -1;
    fop (i,0,b.size() - 1) {
        if (b[i] != b[i + 1]) {
            if (i + 1 == b.size() - 1) {
                cout << p[n - 1] + 1 << endl;
                return 0;
            }
            b[i + 1] += b[i + 2];
            ignore = i + 2;
            break;
        }
    }
    if (ignore == -1) {
        cout << 1 << endl;
    } else {
        vector <int> c;
        fop (i,0,b.size()) if (i != ignore) c.pb(b[i]);
        sort(all(c));
        if (c[0] == c.back()) {
            cout << p[ignore] + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}