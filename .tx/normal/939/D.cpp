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

struct dsu {
    int a[33];

    dsu() {
        rep(i, 0, 33) {
            a[i] = i;
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        a[x] = y;
    }
};

void solve(istream& cin, ostream& cout) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vc<pair<char, char>> ans;
    dsu d;
    rep(i, 0, n) {
        int x = s[i] - 'a';
        int y = t[i] - 'a';
        if (d.get(x) == d.get(y)) {
            continue;
        }
        x = d.get(x);
        y = d.get(y);
        d.a[x] = y;
        ans.emplace_back(x + 'a', y + 'a');
    }
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first << " " << i.second << "\n";
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