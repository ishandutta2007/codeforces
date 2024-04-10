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
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
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

//#define int li
//const int mod = 1000000007;


void solve(__attribute__((unused)) bool read) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> cnt(10);
    for (char c : s) {
        ++cnt[c - '0'];
    }

    int answer = 0;
    for (int t = 0; t <= cnt[8]; ++t) {
        if (accumulate(all(cnt), 0) - t >= t * 10) {
            answer = max(answer, t);
        }
    }
    cout << answer << "\n";
}