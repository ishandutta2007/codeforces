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

struct task {
    int t, q;
    task(){}
};

void solve() {
    int n;
    int T;
    cin >> n >> T;
    vector <task> a(n);
    
    vector <vector <int>> levels(T + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].t >> a[i].q;
        if (a[i].t <= T) {
            levels[T - a[i].t].push_back(a[i].q);
        }
    }

    for (int i = 0; i < levels.size(); ++i) {
        sort(levels[i].rbegin(), levels[i].rend());
    }

    vector <vector <int> > dp(T + 1, vector <int>(n + 1, -1));

    int ans = 0;

    dp[0][1] = 0;

    for (int i = 0; i <= T; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }

            ans = max(ans, dp[i][j]);
            
            if (i == T) {
                continue;
            }

            int sum = 0;        
            for (int x = 0; x <= levels[i].size(); ++x) {
                int tmp = min(2 * (j - x), n);
                if (tmp < 0) {
                    break;
                }

                if (x) {
                    sum += levels[i][x - 1];
                }

                dp[i + 1][tmp] = max(dp[i][j] + sum, dp[i + 1][tmp]);
            }
        }
    }
    
    cout << ans << endl;
}