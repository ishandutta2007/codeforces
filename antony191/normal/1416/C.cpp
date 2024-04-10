#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 2000'000'000, mod = 1000'000'007;
const ll llinf = 1e18;
const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

#define int ll
struct node {
    string s;
    int i;
    node *l, *r;
    node() {
        i = 0;
        l = r = nullptr;
    }
    node(int _i) {
        i = _i;
        l = r = nullptr;
    }
};
const int H = 30;
int cnt[H][2];
const int N = 300'001;
node t[H * N];
int qq = 0;
typedef node* inode;
inline inode new_node(int i) {
    t[qq] = node(i);
    return &t[qq++];
}
inode root;
void add(int c) {
    inode cur = root;
    forn(i, H) {
        if (c & (1 << (H - i - 1))) {
            cur->s += '1';
            if (!cur->r) {
                cur->r = new_node(i + 1);
            }
            cur = cur->r;
        }
        else {
            cur->s += '0';
            if (!cur->l) {
                cur->l = new_node(i + 1);
            }
            cur = cur->l;
        }
    }
}
void dfs(inode v = root) {
    if (!v) return;
    int c = 0;
    forn(i, v->s.size()) {
        if (v->s[i] == '1') c++;
        else cnt[v->i][0] += c;
    }
    c = 0;
    forn(i, v->s.size()) {
        if (v->s[i] == '0') c++;
        else cnt[v->i][1] += c;
    }
    dfs(v->l); dfs(v->r);
}
vector<int> f;
void init(int n) {
    f.resize(n);
}
void upd(int x) {
    for (; x < (int)f.size(); x |= x + 1)
        f[x]++;
}
int sum(int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ans += f[r];
    return ans;
}
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    root = new_node(0);
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
        add(a[i]);
    }
    dfs();
    int x = 0;
    forn(i, H) {
        if (cnt[i][1] < cnt[i][0]) x |= 1 << (H - i - 1);
    }
    forn(i, n) a[i] ^= x;
    vector<int> q;
    forn(i, n) q.push_back(a[i]);
    sort(all(q)); q.resize(distance(q.begin(), unique(all(q))));
    forn(i, n) a[i] = lower_bound(all(q), a[i]) - q.begin();
    ll ans = 0;
    init(n);
    forn(i, n) {
        ans += sum(a[i] + 1, n - 1);
        upd(a[i]);
    }
    cout << ans << ' ' << x << el;
    return 0;
}