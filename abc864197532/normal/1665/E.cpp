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
const int mod = 1e9 + 7, N = 5249, logN = 20, K = 31;

vector <int> operator + (vector <int> a, vector <int> b) {
    vector <int> now(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), now.begin());
    while (now.size() > K)
        now.pop_back();
    return now;
}

struct Seg {
    int l, r, m;
    vector <int> val;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            val.pb(a[l]);
        }
    }
    void pull() {val = ch[0]->val + ch[1]->val;}
    vector <int> query(int a, int b) {
        if (a <= l && r <= b)
            return val;
        vector <int> ans;
        if (a < m)
            ans = ans + ch[0]->query(a, b);
        if (m < b)
            ans = ans + ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Seg root(0, n, a);
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r, --l;
            vector <int> res = root.query(l, r);
            int ans = 1 << 30;
            for (int i = 0; i < res.size(); ++i) for (int j = i + 1; j < res.size(); ++j)
                ans = min(ans, res[i] | res[j]);
            cout << ans << '\n';
        }
    }
}