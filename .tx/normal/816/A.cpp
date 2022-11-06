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

bool is_paly(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

string to_str(int h, int m) {
    string a = to_string(h);
    if (h < 10) {
        a = "0" + a;
    }
    string b = to_string(m);
    if (m < 10) {
        b = "0" + b;
    }
    return a + ":" + b;
}

void solve(istream& cin, ostream& cout) {
    int h, m;
    scanf("%d:%d", &h, &m);
    m += h * 60;
    int ans = 0;
    while (!is_paly(to_str(m / 60, m % 60))) {
        ans++;
        m++;
        m %= 1440;
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