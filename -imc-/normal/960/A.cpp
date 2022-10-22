#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

#define int li

void solve(bool __attribute__((unused)) read) {
    string s;
    cin >> s;
    s += "#";

    int pos = 0;
    int cnt_a = 0, cnt_b = 0, cnt_c = 0;
    while (s[pos] == 'a') { ++pos; ++cnt_a; }
    while (s[pos] == 'b') { ++pos; ++cnt_b; }
    while (s[pos] == 'c') { ++pos; ++cnt_c; }

    cout << ((s[pos] == '#' && cnt_a && cnt_b && (cnt_c == cnt_a || cnt_c == cnt_b)) ? "YES" : "NO") << endl;
}