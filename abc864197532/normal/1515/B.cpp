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
const int mod = 1e9 + 7, N = 400001, logN = 20, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set <int> ok;
    for (int i = 1; i * i <= 1 << 30; ++i) ok.insert(i * i);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool is = false;
        while (n > 1) {
            if (n & 1) break;
            n >>= 1;
            if (ok.count(n)) is = true;
        }
        cout << (is ? "YES\n" : "NO\n");
    }
}