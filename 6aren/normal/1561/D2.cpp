#include <bits/stdc++.h>

using namespace std;

#define int long long

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

void run_case() {
    int n, m;
    cin >> n >> m;
    vector<int> suff(n + 1);
    suff[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        int cur = suff[i + 1];
        for (int j = i + i; j <= n; j += i) {
            int l = j;
            int r = min(j + j / i - 1, n);
            cur = (cur + (suff[l] - (r == n ? 0 : suff[r + 1]) + m)) % m;
        }
        suff[i] = (suff[i + 1] + cur) % m;
    }
    cout << (suff[1] - suff[2] + m) % m << '\n';

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