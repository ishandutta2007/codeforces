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
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, int v = 0) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, int v = 0) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo
#else
#define test(args...)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 111;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int cnt1 = 0, cnt2 = (n & 1 && s[n >> 1] == '0');
        for (int i = 0; i < n - i - 1; ++i) {
            if (s[i] == s[n - i - 1] && s[i] == '0') cnt2 += 2;
            else if (s[i] != s[n - i - 1]) cnt1++;
        }
        function <int(int)> get = [&](int cnt) { // first - second
            if (cnt == 0) return 0;
            if (cnt == 1) return 1;
            if (cnt % 2 == 0) return 2;
            return -1;
        };
        int ans;
        if (cnt1 == 0) ans = get(cnt2);
        else {
            ans = min(-cnt1 + get(cnt2), -cnt1 + 2 - get(cnt2));
        }
        if (ans < 0) cout << "ALICE\n";
        else if (ans == 0) cout << "DRAW\n";
        else cout << "BOB\n";
    }
}