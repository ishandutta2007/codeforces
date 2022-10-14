#pragma GCC optimize("Ofast")  
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int mod = 998244353, N = 1e5 + 7, logN = 18, C = 350;

int main () {
    owo;
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        string t = s;
        swap(t[0], t[1]);
        cout << min(s, t) << endl;
        return 0;
    }
    int m = n >> 1;
    vector <string> now;
    for (int x = 0; x < 1 << m; ++x) {
        for (int i = 0; i < 1 << n; i += 1 << m) {
            string t;
            for (int j = i; j < i + (1 << m); ++j) {
                t.pb(s[j ^ x]);
            }
            now.pb(t);
        }
    }
    sort(all(now)), now.resize(unique(all(now)) - now.begin());
    vector <int> ans(1 << n - m, 1 << 30);
    for (int x = 0; x < 1 << m; ++x) {
        vector <int> a;
        for (int i = 0; i < 1 << n; i += 1 << m) {
            string t;
            for (int j = i; j < i + (1 << m); ++j) {
                t.pb(s[j ^ x]);
            }
            a.pb(lower_bound(all(now), t) - now.begin());
        }
        for (int y = 0; y < 1 << n - m; ++y) {
            vector <int> b;
            for (int i = 0; i < 1 << n - m; ++i) {
                b.pb(a[i ^ y]);
            }
            if (ans > b)
                ans = b;
        }
    }
    for (int i : ans)
        cout << now[i];
    cout << endl;
}