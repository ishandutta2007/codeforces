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

int fs[333];
int ls[333];

void solve(istream& cin, ostream& cout) {
    memset(fs, -1, sizeof(fs));
    int n, k;
    string s;
    cin >> n >> k >> s;
    rep(i, 0, n) {
        if (fs[s[i]] == -1) {
            fs[s[i]] = i;
        }
        ls[s[i]] = i;
    }
    int c = 0;
    rep(i, 0, n) {
        if (fs[s[i]] == i) {
            c++;
        }
        if (c > k) {
            cout << "YES";
            return;
        }
        if (ls[s[i]] == i) {
            c--;
        }
    }

    cout << "NO";
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