#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        ll t;
        cin >> n >> t;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (a[i] > t) {
                continue;
            }
            if (t % 2 == 0 && a[i] == t / 2) {
                continue;
            }
            if (a[i] <= t / 2) {
                ans[i] = 1;
            }
        }
        if (t % 2 == 0) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == t / 2) {
                    cnt++;
                }
            }
            int num = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == t / 2) {
                    num++;
                    if (num <= cnt / 2) {
                        ans[i] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}