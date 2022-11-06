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
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    map<char, int> m;
    for (char c : s) {
        m[c]++;
    }
    if (m.size() > 4 || m.size() < 2) {
        cout << "No";
        return;
    }
    if (m.size() == 4) {
        cout << "Yes";
        return;
    }
    vector<int> a;
    for (auto& i : m) {
        a.push_back(i.second);
    }
    sort(a.rbegin(), a.rend());
    if (a.size() == 2) {
        if (a.back() > 1) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        return;
    }
    if (a.front() > 1) {
        cout << "Yes";
    } else {
        cout << "No";
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