#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

void precalc() {
}

#define int li
const int mod = 1000000007;

void solve(bool read) {
    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ++deg[a]; ++deg[b];
    }
    int l = 0;
    for (int i = 0; i < n; ++i) {
        l += deg[i] == 1;
    }

    int ans = (n + l) % mod;
    for (int i = 0; i < n - l; ++i) {
        ans = ans * 2 % mod;
    }

    cout << ans << endl;

}