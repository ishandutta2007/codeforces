/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 300001, logN = 20, K = 350;

struct Seg {
    int l, r, m, mn;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            mn = a[l];
        }
    }
    void pull() {mn = min(ch[0]->mn, ch[1]->mn);}
    void set(int p, int v) {
        if (r - l == 1)
            mn = v;
        else
            ch[p >= m]->set(p, v), pull();
    }
    int query(int a, int b) {
        if (a <= l && r <= b)
            return mn;
        int ans = 1 << 30;
        if (a < m)
            ans = min(ans, ch[0]->query(a, b));
        if (m < b)
            ans = min(ans, ch[1]->query(a, b));
        return ans;
    }
};

queue <int> pos[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        while (!pos[i].empty())
            pos[i].pop();
    }
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], a[i]--, pos[a[i]].push(i);
    Seg root(0, n, a);
    bool is = true;
    int now = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x, --x;
        if (!is || pos[x].empty()) {
            is = false;
            continue;
        }
        int id = pos[x].front(); pos[x].pop();
        if (now >= id) {
            now++;
        } else if (root.query(now, id) > x) {
            root.set(id, 1 << 30);
        } else {
            is = false;
        }
    }
    cout << (is ? "YES\n" : "NO\n");
}

int main() {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}