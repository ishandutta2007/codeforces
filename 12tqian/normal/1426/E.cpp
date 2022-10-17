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
    ll n;
    cin >> n;
    ll a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    ll b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    ll mx = min(a1, b2) + min(a2, b3) + min(a3, b1);
    swap(b1, b2);
    swap(b2, b3);
    ll mn = max(a1 + b1 - n, 0LL) + max(a2 + b2 - n, 0LL) + max(a3 + b3 - n, 0LL);
    cout << mn << " " << mx << '\n';
}