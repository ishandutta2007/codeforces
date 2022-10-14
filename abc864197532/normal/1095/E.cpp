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

template <typename T>
struct Seg {
    int l, r, m;
    T sum, addTag;
    Seg* ch[2];
    Seg (int l, int r): l(l), r(r), m(l + r >> 1) {
        sum = addTag = 0;
        if (r - l != 1) {
            ch[0] = new Seg <T>(l, m);
            ch[1] = new Seg <T>(m, r);
            pull();
        }
    }
    int size() {return r - l;}
    void pull() {sum = min(ch[0]->sum, ch[1]->sum);}
    void addValue(T v) {sum += v;};
    void push() {
        if (addTag) {
            if (r - l != 1) {
                ch[0]->addValue(addTag);
                ch[0]->addTag += addTag;
                ch[1]->addValue(addTag);
                ch[1]->addTag += addTag;
            }
            addTag = 0;
        }
    }
    void set(int p, T v) {
        if (r - l == 1) {
            sum = v;
        } else {
            push();
            if (p < m) {
                ch[0]->set(p,v);
            } else {
                ch[1]->set(p,v);
            }
            pull();
        }
    }
    T query(int a, int b) {
        if (a <= l and r <= b) return sum;
        push();
        T ans = 864197532;
        if (a < m) ans = min(ans, ch[0]->query(a,b));
        if (m < b) ans = min(ans, ch[1]->query(a,b));
        return ans;
    }
    void add(int a, int b, T v) {
        if (a >= b) return;
        if (a <= l and r <= b) {
            addValue(v);
            addTag += v;
        } else {
            push();
            if (a < m) ch[0]->add(a,b,v);
            if (m < b) ch[1]->add(a,b,v);
            pull();
        }
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) {cout << 0 << endl; return 0;}
    int a = count(all(s), '('), b = count(all(s), ')');
    if (abs(a - b) != 2) {cout << 0 << endl; return 0;}
    Seg <lli> root(0, n);
    int now = 0, ans = 0;
    fop (i,0,n) now += (s[i] == '(' ? 1 : -1), root.set(i, now);
    fop (i,0,n) {
        if (s[i] == '(') {
            if (a > b) {
                root.add(i, n, -2);
                ans += (root.query(0, n) == 0);
                root.add(i, n, 2);
            }
        } else {
            if (a < b) {
                root.add(i, n, 2);
                ans += (root.query(0, n) == 0);
                root.add(i, n, -2);
            }
        }
    }
    cout << ans << endl;
}