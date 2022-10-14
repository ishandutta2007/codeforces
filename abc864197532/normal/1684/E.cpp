#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")  
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int mod = 998244353, N = 1000087, logN = 19, K = 111, M = 1000006;

void solve() {
    int n, k;
    cin >> n >> k;
    map <int, int> m1;
    for (int i = 0, x; i < n; ++i)
        cin >> x, m1[x]++;
    auto ask = [&](int sz) {
        priority_queue <int, vector <int>, greater <int>> pq;
        int cnt1 = 0, cntg = 0;
        for (auto [x, y] : m1) {
            if (x < n)
                cnt1++;
            if (x > n) {
                pq.push(y);
                if (pq.size() > sz)
                    cntg += pq.top(), pq.pop();
            }
        }
        int ans = n;
        for (int mex = n; mex >= 0; --mex) {
            // < mex need to have at least 1
            // = mex : delete all
            // > mex only have x remain
            {
                int c = cntg + (m1.count(mex) ? m1[mex] : 0);
                if (c < mex - cnt1)
                    c = mex - cnt1;
                ans = min(ans, c);
            }
            // update
            if (m1.count(mex)) {
                pq.push(m1[mex]);
                if (pq.size() > sz)
                    cntg += pq.top(), pq.pop();
            }
            if (m1.count(mex - 1)) {
                cnt1--;
            }
        }
        return ans;
    };
    int l = -1, r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (ask(m) <= k)
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}