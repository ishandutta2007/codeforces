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
    int n;
    cin >> n;
    auto ask = [&](int l, int r) -> int {
        cout << "? " << l + 1 << " " << r + 1 << endl;
        int x;
        cin >> x;
        return x;
    };
    vector<int> ans(n);
    int v1 = ask(0, 1);
    int v2 = ask(1, 2);
    int v3 = ask(0, 2);
    ans[0] = v3 - v2;
    ans[2] = v3 - v1;
    ans[1] = v3 - ans[0] - ans[2];
    for (int i = 3; i < n; i++) {
        int v = ask(i - 1, i);
        ans[i] = v - ans[i - 1];
    }
    cout << '!' << " ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}