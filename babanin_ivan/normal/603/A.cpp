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
    //freopen("output.txt", "w", stdout);
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

int dp[101000][2][3];

void solve() {
    int n;
    cin >> n;

    int maxv = 0;

    for (int i = 0; i < n; ++i) {
        char p;
        cin >> p;
        int c = p - '0';

        for (int j = 0; j <= 2; ++j) {
            for (int t = 0; t < 2; ++t) {
                dp[i + 1][t][j] = dp[i][t][j];
            }
        }

        for (int j = 0; j <= 2; ++j) {
            if (j < 2) {
                dp[i + 1][c][j + 1] = max(dp[i + 1][c][j + 1], dp[i][c][j] + 1);
            }
            dp[i + 1][c][j] = max(dp[i + 1][c][j], dp[i][!c][j] + 1);
        }
    }

    for (int u = 0; u < 2; ++u) {
        for (int p = 0; p <= 2; ++p) {
            maxv = max(maxv, dp[n][u][p]);
        }
    }
    cout << maxv;
}