#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool read);

int main() {
    auto t0 = clock();
#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout.precision(20);
    cout << fixed;

    solve(true);
#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif
}

bool isp(string s) {
    string x = s;
    reverse(all(x));
    return x == s;
}

void solve(bool __attribute__((unused)) read) {
    string s;
    cin >> s;

    int n = s.length();

    pair<int, string> answer(0, "");
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (!isp(s.substr(i, j - i + 1))) {
                answer = max(answer, make_pair(j - i + 1, s.substr(i, j - i + 1)));
            }

    cout << answer.first << endl;
}