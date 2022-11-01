#pragma comment (linker, "/STACK:128000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <sstream>
#include <stack>
#include <cassert>
#include <list>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;

    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

#define int li

void solve() {
    int n;
    cin >> n;

    vector <int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }


    vector <vector <string>> a(n, vector <string>(2));
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = a[i][0];
        reverse(all(a[i][1]));
    }


    vector <vector <int> > dp(n, vector <int> (2, -1));
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int u = 0; u < 2; ++u) {
                if (dp[i - 1][u] < 0) {
                    continue;
                }
                if (a[i][j] >= a[i - 1][u]) {
                    if (dp[i][j] < 0 || dp[i][j] > dp[i - 1][u] + j * c[i]) {
                        dp[i][j] = dp[i - 1][u] + j * c[i];
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < 2; ++i) {
        if (ans < 0) {
            ans = dp[n - 1][i];
        }
        if (dp[n - 1][i] >= 0 && ans > dp[n - 1][i]) {
            ans = dp[n - 1][i];
        }
    }
    cout << ans << endl;
}