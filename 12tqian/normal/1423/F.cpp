#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    ll n, k; 
    cin >> n >> k;
    ll sum1 = 0;
    ll sum2 = 0;
    for (ll i = 0; i < k; i++) {
        ll a, b;
        cin >> a >> b;
        sum1 += b;
        sum2 += a * b;
        sum2 %= n;
    }
    if (sum1 > n) {
        cout << -1 << '\n';
    } else if (sum1 < n) {
        cout << 1 << '\n'; 
    } else if (sum2 == ((n * (n + 1) / 2) % n)) { 
        cout << 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}