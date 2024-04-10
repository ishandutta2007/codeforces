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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
#define test(args...) info(), abc("[" + string(#args) + "]", args)
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
const int N = 2001, logN = 20, K = 111;

int T = 60000;

int query_range(int l, int r) {
    T--;
    assert(T >= 0);
    cout << "? " << l + 1 << ' ' << r << endl;
    cin >> l;
    return l;
}

struct Seg {
    int l, r, m, sum;
    Seg* ch[2];
    Seg (int _l, int _r) : l(_l), r(_r), m(l + r >> 1), sum(-1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m);
            ch[1] = new Seg(m, r);
        }
    }
    int get() {
        if (sum == -1) return sum = r - l - query_range(l, r);
        return sum;
    }
    int query(int k) {
        sum--;
        if (r - l == 1) return l;
        if (ch[0]->get() < k) {
            k -= ch[0]->get();
            return ch[1]->query(k);
        }
        return ch[0]->query(k);
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin >> n >> t;
    Seg root(0, n);
    while (t--) {
        cin >> k;
        int p = root.query(k);
        cout << "! " << p + 1 << endl;
    }
}