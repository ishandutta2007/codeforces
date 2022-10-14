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
const int mod = 998244353, N = 200005, logN = 20, K = 111;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n), k(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> k[i];
    lli p = -1, q = 1;
    vector <int> pp(N, 0), tans;
    iota(all(pp), 0);
    for (int ans = 1; ans <= 21; ++ans) {
        vector <lli> cnt(N, 0);
        for (int i = 0; i < n; ++i) {
            if (k[i] >= ans)
                cnt[a[i]] += ans;
            else
                cnt[a[i]] += k[i];
        }
        sort(all(pp), [&](int i, int j) {
            if (cnt[i] == cnt[j])
                return i > j;
            return cnt[i] > cnt[j];
        });
        lli al = 0;
        for (int i = 0; i < ans; ++i)
            al += cnt[pp[i]];
        if (p * ans < al * q) {
            p = al, q = ans;
            tans.clear();
            for (int i = 0; i < ans; ++i)
                tans.pb(pp[i]);
        }
    }
    cout << q << endl;
    printv(all(tans));
}