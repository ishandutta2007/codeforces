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

void run_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
        pos[a[i]].push_back(i);
    }
    if (abs((int) pos[0].size() - (int) pos[1].size()) > 1) {
        cout << -1 << '\n';
        return;
    }

    long long res = 1e18;
    for (int i = 0; i < 2; i++) {
        if (pos[i].size() >= pos[1 - i].size()) {
            long long tmp = 0;
            for (int j = 0; j < pos[i].size(); j++) {
                tmp += abs(pos[i][j] - j * 2);
            }
            res = min(res, tmp);
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
    cin >> tests;
    while (tests--) run_case();
    return 0;
}