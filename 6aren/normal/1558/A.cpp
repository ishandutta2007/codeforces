#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    vt << '[';
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
    int a, b;
    cin >> a >> b;
    vector<int> u;
    if ((a + b) % 2) u.push_back((a + b) / 2), u.push_back((a + b) / 2 + 1);
    else u.push_back((a + b) / 2);
    set<int> k;
    for (int uu : u) {
        for (int x2 = 0; x2 <= uu; x2++) {
            int x1 = uu - x2;
            int y1 = a - x2;
            int y2 = b - x1;
            if (x1 >= 0 && y1 >= 0 && y2 >= 0) k.insert(x2 + y2);
        }
    }
    cout << k.size() << '\n';
    for (int e : k) cout << e << ' ';
    cout << '\n';
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