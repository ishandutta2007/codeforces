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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    vector <lli> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    lli sum = accumulate(all(a), 0ll);
    if (sum < 0) {
        for (int i = 0; i < n; ++i)
            a[i] *= -1;
        sum = -sum;
    }
    int num = count(all(a), 0);
    vector <lli> can;
    while (sum >= k)
        can.pb(-k), sum -= k;
    if ((num ^ int(can.size())) & 1) 
        can.pb(-sum);
    else {
        if (sum != 0)
            can.pb(-k), can.pb(k - sum);
    }
    if (can.size() > num)
        return cout << -1 << '\n', 0;
    while (can.size() < num) { 
        can.pb(-k), can.pb(k);
    }
    assert(can.size() == num);
    sort(rall(can));
    lli ans = 0;
    for (int t = 0; t < n; ++t) {
        vector <lli> now = a;
        int c = 0;
        for (int i = 0; i < n; ++i) if (now[i] == 0)
            now[i] = can[c++];
        lli mx = 0, mn = 0, pre = 0;
        for (lli i : now)
            pre += i, mx = max(mx, pre), mn = min(mn, pre);
        ans = max(ans, mx - mn);
        rotate(a.begin(), a.begin() + 1, a.end());
    }
    cout << ans + 1 << '\n';
}