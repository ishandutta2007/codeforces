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

int p[222222];
int a[222222];
int b[222222];
vector<int> d[4];

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> p[i];
    }
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }
    rep(i, 0, n) {
        d[a[i]].push_back(p[i]);
        if (a[i] != b[i]) {
            d[b[i]].push_back(p[i]);
        }
    }
    rep(i, 1, 4) {
        sort(d[i].rbegin(), d[i].rend());
    }

    int m;
    cin >> m;
    set<int> was;
    rep(i, 0, m) {
        int x;
        cin >> x;
        while (!d[x].empty() && was.count(d[x].back())) {
            d[x].pop_back();
        }
        if (d[x].empty()) {
            cout << "-1 ";
            continue;
        }
        int a = d[x].back();
        cout << a << " ";
        was.insert(a);
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