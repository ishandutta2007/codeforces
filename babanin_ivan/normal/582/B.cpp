#pragma comment (linker, "/STACK:256000000")
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

int n, T;

int dp2[25][100][100];

void solve() {
    cin >> n >> T;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    vector <vector <int> > go(b.size(), vector <int>(b.size()));

    for (int i = 0; i < n; ++i) {
        vector <int> dp(n, 0);
        for (int j = 0; j < n; ++j) {
            if (a[j] >= a[i]) {
                dp[j] = 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int x = j + 1; x < n; ++x) {
                if (dp[j] && a[x] >= a[j] && dp[x] < dp[j] + 1) {
                    dp[x] = dp[j] + 1;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            go[a[i]][a[j]] = max(go[a[i]][a[j]], dp[j]);
        }
    }
    for (int i = 0; i < go.size(); ++i) {
        for (int j = 1; j < go.size(); ++j) {
            go[i][j] = max(go[i][j], go[i][j - 1]);
        }
    }


    for (int i = 0; i < b.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            dp2[0][i][j] = go[i][j];
        }
    }
    
    for (int t = 1; t < 25; ++t) {
        for (int i = 0; i < b.size(); ++i) {
            for (int j = i; j < b.size(); ++j) {
                for (int u = i; u <= j; ++u) {
                    dp2[t][i][j] = max(dp2[t][i][j], dp2[t - 1][i][u] + dp2[t - 1][u][j]);
                }
            }
        }
    }
    vector <int> cur(b.size());

    for (int t = 0; t < 25; ++t) {
        if ((1 << t) & T) {
            vector <int> cur2(b.size());
            for (int i = 0; i < b.size(); ++i) {
                for (int j = i; j < b.size(); ++j) {
                    cur2[j] = max(cur2[j], cur[i] + dp2[t][i][j]);
                }
            }
            cur = cur2;
        }
    }

    int x = *max_element(cur.begin(), cur.end());
    cout << x;
}