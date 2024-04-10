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

int a[2222];
int b[2222];

void solve(istream& cin, ostream& cout) {
    int n, k;
    cin >> k >> n;

    int s = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        s += x;
        a[i] = s;
    }

    rep(i, 0, n) {
        cin >> b[i];
    }

    int ans = 0;
    set<int> w;
    rep(i, 0, k) {
        if (w.count(a[i])) {
            continue;
        }
        w.insert(a[i]);
        multiset<int> bb;
        rep(i, 0, n) {
            bb.insert(b[i]);
        }
        int x = b[0] - a[i];
        bb.erase(bb.find(b[0]));

        int i1 = 0;
        while (i1 < k && bb.size()) {
            if (bb.find(x + a[i1]) != bb.end()) {
                bb.erase(bb.find(x + a[i1]));
            }
            i1++;
        }
        if (bb.empty()) {
            ans++;
        }
    }

    cout << ans;
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
}//yo