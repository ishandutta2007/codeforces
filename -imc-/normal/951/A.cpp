#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read);

#define int li

ostream& dbgPrintContainer(ostream& os, const auto& container, const char* brackets = "[]") {
    os << brackets[0] << " ";
    for (auto& elem : container) {
        os << elem << " ";
    }
    os << brackets[1];
    return os;
}

ostream& operator<<(ostream& os, const pair<auto, auto>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}

ostream& operator<<(ostream& os, const vector<auto>& v) { return dbgPrintContainer(os, v, "[]"); }
ostream& operator<<(ostream& os, const set<auto>& v) { return dbgPrintContainer(os, v, "{}"); }
ostream& operator<<(ostream& os, const map<auto, auto>& v) { return dbgPrintContainer(os, v, "{}"); }

signed main() {
    auto t0 = clock();
    cout << fixed << setprecision(12);

#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

#if 0
    while (true) {
        solve(false);
    }
#endif

#ifdef YA
    cerr << endl << endl << fixed << setprecision(5) << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

void solve(bool __attribute__((unused)) read) {
    string s;
    cin >> s;
    int n = s.length();
    s = s + s;
//    for (int i = 0; i < n + n; ++i) {
//        if (i % 2) {
//            s[i] = (s[i] == 'b') ? 'w' : 'b';
//        }
//    }

    vector<int> a(n + n, 1);
    for (int i = 1; i < n + n; ++i) {
        if (s[i] == s[i - 1]) {
            a[i] = 1;
        } else {
            a[i] = a[i - 1] + 1;
        }
    }

    cout << min(n, *max_element(all(a))) << "\n";
}