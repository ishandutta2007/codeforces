#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    int n = s.size();
    set<int> z, o;
    rep(i, 0, n) {
        if (s[i] == '0') {
            z.insert(i);
        } else {
            o.insert(i);
        }
    }

    vc<vc<int>> ans;

    while (!z.empty()) {
        vc<int> cr;
        cr.push_back(*z.begin());
        z.erase(z.begin());
        while (true) {
            auto x = o.upper_bound(cr.back());
            if (x == o.end()) {
                break;
            }
            auto y = z.upper_bound(*x);
            if (y == z.end()) {
                break;
            }
            cr.push_back(*x);
            cr.push_back(*y);
            o.erase(x);
            z.erase(y);
        }
        ans.push_back(cr);
    }

    if (!o.empty()) {
        cout << -1;
        return;
    }
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.size();
        for (int j : i) {
            cout << " " << j + 1;
        }
        cout << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}