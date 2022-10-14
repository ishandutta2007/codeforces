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
const int mod = 998244353, N = 1 << 19, logN = 20;

void solve() {
    int n;
    cin >> n;
    vector <lli> a(n);
    int cnt0 = 0, cntpos = 0, cntneg = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i], cnt0 += a[i] == 0, cntpos += a[i] > 0, cntneg += a[i] < 0;
    if (cntpos >= 3 || cntneg >= 3) {
        cout << "NO\n";
        return;
    }
    vector <lli> now;
    for (int i = 0; i < min(cnt0, 2); ++i) {
        now.pb(0);
    }
    for (int i = 0; i < n; ++i) if (a[i] != 0)
        now.pb(a[i]);
    int m = now.size();
    for (int i = 0; i < m; ++i) for (int j = i + 1; j < m; ++j) for (int k = j + 1; k < m; ++k) {
        if (find(all(now), now[i] + now[j] + now[k]) == now.end()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}