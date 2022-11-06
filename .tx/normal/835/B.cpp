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

int cnt[11];

void solve(istream& cin, ostream& cout) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
        cnt[c - '0']++;
    }
    int ans = 0;
    for (int i = 0; sum < k;) {
        if (cnt[i] == 0) {
            i++;
            continue;
        }
        sum += 9 - i;
        cnt[i]--;
        ans++;
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
}