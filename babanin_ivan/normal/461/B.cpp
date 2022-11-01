#include <iostream> 
#include <cstdio> 
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
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

const li mod = 1000000007;

int n;
vector < vector <int> > g;
vector <li> dp[2];
vector <int> x;

void dfs(int v, int p) {
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs(to, v);
    }
    if (x[v] == 0) {
        dp[0][v] = 1;
        dp[1][v] = 0;
        
        //1
        vector < pair <int, int> > godp;

        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (to != p) {
                godp.push_back(mp(dp[0][to], dp[1][to]));
            }
        }
        if (godp.size() == 0)
            return ;

        vector <li> prefsum(godp.size());
        vector <li> sufsum(godp.size());
        li cur = 1;
        for (int i = 0; i < godp.size(); ++i) {
            cur = ((cur * godp[i].first) % mod + (cur * godp[i].second) % mod) % mod;
            prefsum[i] = cur; 
        }
        cur = 1;
        for (int i = godp.size() - 1; i >= 0; --i) {
            cur = ((cur * godp[i].first) % mod + (cur * godp[i].second) % mod) % mod;
            sufsum[i] = cur;
        }
        
        for (int i = 0; i < godp.size(); ++i) {
            li tmp = godp[i].second;
            if (i > 0) {
                tmp = (tmp * prefsum[i - 1]) % mod;
            }
            if (i < godp.size() - 1) {
                tmp = (tmp * sufsum[i + 1]) % mod;
            }
            dp[1][v] = (dp[1][v] + tmp) % mod;
        }
        
        // 0
        dp[0][v] = prefsum.back();
    }
    else {
        dp[0][v] = 0;
        dp[1][v] = 1;
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (to == p)
                continue;
            dp[1][v] = ((dp[1][v] * dp[1][to]) % mod + (dp[1][v] * dp[0][to]) % mod) % mod;
        }
    }
}

void solve() {
    cin >> n;
    g.resize(n);
    dp[0].resize(n);
    dp[1].resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i + 1);
        g[i + 1].push_back(p);
    }
    x.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    dfs(0, -1);
    cout << dp[1][0] << endl;
}