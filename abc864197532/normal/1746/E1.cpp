#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 20, K = 250;

vector <int> com(vector <int> a, vector <int> b) {
    for (int i : b) a.pb(i);
    return a;
}

bool ask(vector <int> a) {
    cout << "? " << a.size();
    for (int i : a)
        cout << ' ' << i;
    cout << endl;
    string s; cin >> s;
    return s == "YES";
}

void solve() {
    int n;
    cin >> n;
    vector <int> cur(n);
    iota(all(cur), 1);
    while (n >= 4) {
        vector <int> a[4];
        for (int i = 0; i < n; ++i)
            a[i % 4].pb(cur[i]);
        vector <int> nxt;
        int x = ask(com(a[0], a[1]));
        int y = ask(com(a[0], a[2]));
        if (x && y) {
            nxt = a[0];
            nxt = com(nxt, com(a[1], a[2]));
        } else if (x) {
            nxt = a[0];
            nxt = com(nxt, com(a[1], a[3]));
        } else if (y) {
            nxt = a[0];
            nxt = com(nxt, com(a[2], a[3]));
        } else {
            nxt = a[1];
            nxt = com(nxt, com(a[2], a[3]));
        }
        n = nxt.size();
        cur = nxt;
    }
    if (n <= 2) {
        for (int x : cur) {
            cout << "! " << x << endl;
            string s; cin >> s;
            if (s == ":)") return;
        }
        assert(false);
    }
    int res = ask({cur[0]}) + ask({cur[1]}) * 2 + ask({cur[1]}) * 4 + ask({cur[0]}) * 8;
    vector <int> table = {5, 5, 6, 3, 6, 4, 2, 2, 5, 5, 4, 1, 3, 1, 2, 2};
    for (int i = 0; i < 3; ++i) if (table[res] >> i & 1) {
        cout << "! " << cur[i] << endl;
        string s; cin >> s;
        if (s == ":)") return;
    }
    /*
    int m = 4, k = 3, tmp = (1 << k) - 2;
    int bound = pow(tmp, m);
    for (int s = 0; s < bound; ++s) {
        vector <int> a;
        int x = s;
        for (int j = 0; j < m; ++j) {
            a.pb(x % tmp + 1), x /= tmp;
        }
        vector <int> ans(k);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) if (a[j] >> i & 1)
                ans[i] |= 1 << j;
        }
        map <int, int> m1;
        for (int i = 0; i < k; ++i) {
            for (int t = 0; t < 1 << m; ++t) {
                bool is = true;
                for (int i = 0; i < m; ++i) if (t >> i & 1 && t >> i + 1 & 1)
                    is = false;
                if (is)
                    m1[ans[i] ^ t] |= 1 << i;
            }
        }
        bool fail = false;
        for (auto [x, y] : m1) fail |= y == (1 << k) - 1;
        if (!fail) {
            for (auto [x, y] : m1)
            test(x, y);
        }
    }*/
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}