#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << "\n"
#define test(args...) info(), kout("[" + string(#args) + "]", args)
void kout() {cerr << endl;}
template <typename T, class ...U>
void kout(vector <T> a, U ...b) {for (T i : a) cerr << i << ' '; kout(b...);}
template <class T, class ...U>
void kout(T a, U ...b) {cerr << a << ' ', kout(b...);}
template <class T>
void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a) {
    return o << a.X << ' ' << a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 400001, K = 111;
#define pll pair<lli, lli>

pll fraction (lli a, lli b) {
    lli g = __gcd(a, b);
    a /= g, b /= g;
    return mp(a, b);
};

struct Pt {
    lli a, b, c, d;
    void x_add_one() {a += b;}
    void x_minus_one() {a -= b;}
    void y_add_one() {c += d;}
    void y_minus_one() {c -= d;}
    pll m() {return fraction(a * d, b * c);}
} a[N];

vector <pii> adj[N];
bool vis[N];
int dep[N];
vector <pii> ans;

bool dfs(int v, int pa, int _id) {
    vis[v] = true;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    vector <int> could_pair;
    for (auto [u, id] : adj[v]) if (u != pa) {
        if (vis[u]) {
            if (dep[v] < dep[u]) could_pair.pb(id);
        } else {
            if (dfs(u, v, id)) could_pair.pb(id);
        }
    }
    while (could_pair.size() >= 2) {
        int x = could_pair.back(); could_pair.pop_back();
        int y = could_pair.back(); could_pair.pop_back();
        ans.eb(x, y);
    }
    if (~pa && !could_pair.empty()) {
        ans.eb(could_pair.back(), _id);
        could_pair.pop_back();
        return false;
    }
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, _id = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    map <pll, int> m1;
    for (int i = 0; i < n; ++i) {
        a[i].x_add_one();
        pll A = a[i].m();
        if (!m1.count(A)) m1[A] = _id++;
        a[i].x_minus_one();
        a[i].y_add_one();
        pll B = a[i].m();
        if (!m1.count(B)) m1[B] = _id++;
        a[i].y_minus_one();
        adj[m1[A]].eb(m1[B], i + 1);
        adj[m1[B]].eb(m1[A], i + 1);
    }
    for (int i = 0; i < _id; ++i) if (!vis[i]) dfs(i, -1, 0);
    cout << ans.size() << endl;
    for (pii A : ans) cout << A.X << ' ' << A.Y << endl;
}