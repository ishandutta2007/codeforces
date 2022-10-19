#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long

void run_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    long long res = 0;
    for (int i = 0; i < n; i += 2) {
        int l = 0, r = a[i] - 1;
        int cur = a[i];
        for (int j = i + 1; j < n; j++) {
            if (j % 2 == i % 2) {
                cur += a[j];
                continue;
            }
            int down = cur - a[j];
            int foo = max(down, l);
            if (foo <= r) {
                res += r - foo + 1;
                // dbg(i, j, r, foo);
                r = down;
            }
            if (r < l) break;
            cur = down;
        }
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    while (tests--) run_case();
    return 0;
}