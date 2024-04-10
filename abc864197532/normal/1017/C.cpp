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
const int mod = 998244353, N = 2e6 + 5, logN = 20, M = 6e6;

int main () {
    owo;
    /*
     1
     1 2
     3 1 2
     3 4 1 2

     10 11 12 7 8 9 4 5 6 1 2 3
     */
    /*
    for (int n = 1; n <= 10; ++n) {
        vector <int> p(n);
        iota(all(p), 0);
        auto lis = [&](vector <int> a) {
            vector <int> v;
            for (int i : a) {
                if (v.empty() || v.back() < i)
                    v.pb(i);
                else
                    *lower_bound(all(v), i) = i;
            }
            return v.size();
        };
        int ans = 1 << 30;
        do {
            int res = lis(p);
            reverse(all(p));
            res += lis(p);
            reverse(all(p));
            ans = min(ans, res);
        } while (next_permutation(all(p)));
        cout << ans << endl;
    }*/
    int n;
    cin >> n;
    int sq = 1;
    while (sq * sq < n)
        sq++;
    vector <int> block(sq);
    for (int i = 0; i < n; ++i)
        block[i % sq]++;
    vector <vector <int>> ans(sq);
    int now = 1;
    for (int i = sq - 1; ~i; --i) {
        for (int j = 0; j < block[i]; ++j)
            ans[i].pb(now++);
    }
    for (int i = 0; i < sq; ++i) {
        for (int j : ans[i])
            cout << j << ' ';
    }
    cout << endl;
}