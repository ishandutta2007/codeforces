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
const int mod = 998244353, N = 2005, logN = 18, K = 1 << 8;

struct event {
    int x, l, r, v;
    bool operator < (const event &o) {
        return x < o.x;
    }
};

vector <int> v;

struct Seg {
    int l, r, m, lz, sum;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), lz(0), sum(0) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    void pull() {
        if (lz)
            sum = v[r] - v[l];
        else
            sum = r - l > 1 ? ch[0]->sum + ch[1]->sum : 0;
    }
    void modify(int a, int b, int v) {
        if (a <= l && r <= b)
            lz += v;
        else {
            if (a < m)
                ch[0]->modify(a, b, v);
            if (m < b)
                ch[1]->modify(a, b, v);
        }
        pull();
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        /* 
         (x, y), x > 1, y > 1
         (lx, ly) (x, y) (rx, ry)
         lx <= x && ly <= y, x < n - sx + lx, y < n - sy + ly
         lx <= x < n - sx + lx
         ly <= y < n - sy + ly
         lx >= 1, ly >= 1
         */
        int sx = count(all(s), 'D'), sy = count(all(s), 'R');
        if (sx >= n || sy >= n) {
            cout << 0 << endl;
            continue;
        }
        vector <event> E;
        v.clear();
        {
            int lx = 0, ly = 0;
            for (char c : s) {
                if (c == 'D')
                    lx++;
                else
                    ly++;
                if (lx && ly) {
                    int a = lx, b = min(n - sx + lx, n);
                    int c = ly, d = min(n - sy + ly, n);
                    if (a < b && c < d) {
                        E.pb({a, c, d, 1}), E.pb({b, c, d, -1});
                        v.pb(c), v.pb(d);
                    }
                }
            }
        }
        sort(all(E));
        sort(all(v)), v.resize(unique(all(v)) - v.begin());
        lli ans = 0;
        int m = v.size();
        if (!E.empty()) {
            Seg root(0, m);
            int lst = 0;
            for (int i = 0, j = 0; i < E.size(); i = j) {
                ans += 1ll * root.sum * (E[i].x - lst);
                while (j < E.size() && E[i].x == E[j].x) {
                    int l = lower_bound(all(v), E[j].l) - v.begin();
                    int r = lower_bound(all(v), E[j].r) - v.begin();
                    root.modify(l, r, E[j].v);
                    j++;
                }
                lst = E[i].x;
            }
        }
        if (s[0] == 'R') {
            int j = 0;
            while (j < s.size() && s[j] == 'R') {
                j++;
            }
            ans += n - (sy - j);
        } else {
            int j = 0;
            while (j < s.size() && s[j] == 'D') {
                j++;
            }
            ans += n - (sx - j);
        }
        cout << ans << endl;
    }
}