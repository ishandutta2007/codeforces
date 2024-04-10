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

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    set<int> a, b;
    rep(i, 0, n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    rep(i, 0, m) {
        int x;
        cin >> x;
        b.insert(x);
    }
    for (int i : a) {
        if (b.count(i)) {
            cout << i;
            return;
        }
    }
    if (*a.begin() > *b.begin()) {
        swap(a, b);
    }
    cout << *a.begin() << *b.begin();
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