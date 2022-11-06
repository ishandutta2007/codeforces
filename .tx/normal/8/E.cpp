#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, z, n) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

vector<int> to_bin(int x, int n) {
    vector<int> res;
    rep(i, 0, n) {
        res.push_back(x & 1);
        x >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int inv(int x, int n) {
    int res = 0;
    rep(i, 0, n) {
        res = (res << 1) | (x & 1);
        x >>= 1;
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
    int n;
    lint k;
    cin >> n >> k;
    rep(i, 0, shl((n - 1) / 2)) {
        int l = i;
        if (n & 1) {
            l >>= 1;
        }
        int r = l ^ (shl(n / 2) - 1);
        if ((n & 1) && (i & 1)) {
            r--;
        }
        if (l > r) {
            continue;
        }
        int c = r - l + 1;
        if (k >= c) {
            k -= c;
            continue;
        }
        vector<int> lb = to_bin(i, (n + 1) / 2);
        for (int& x : lb) {
            cout << x;
        }
        vector<int> rb;
        rep(j, 0, shl(n / 2)) {
            int inv_j = inv(j, n / 2);
            if (inv_j >= l && inv_j <= r) {
                if (k == 0) {
                    rb = to_bin(j, n / 2);
                    break;
                }
                k--;
            }
        }
        for (int& x : rb) {
            cout << x;
        }

        return;
    }
    cout << -1;
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
}//oqylbz