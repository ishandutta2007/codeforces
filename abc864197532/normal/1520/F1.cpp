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
const int N = 300000, logN = 20, K = 111;

int query(int l, int r) {
    cout << "? " << l + 1 << ' ' << r << endl;
    cin >> l;
    return l;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin >> n >> t >> k;
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = l + r >> 1;
        int tmp = mid - l - query(l, mid);
        if (tmp < k) l = mid, k -= tmp;
        else r = mid;
    }
    cout << "! " << r << endl;
}