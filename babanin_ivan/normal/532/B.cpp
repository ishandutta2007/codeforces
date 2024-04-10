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

vector <int> a;
vector <vector <int> > g;
vector < vector <li> > dp;


struct fuck {
    
};

void get(int v) {
    if (g[v].size() == 0) {
        dp[v][0] = 0;
        dp[v][1] = -1;
        return;
    }

    for (int to: g[v]) {
        get(to);
    }

    dp[v][0] = 0;
    dp[v][1] = 0;

    vector <pair <li, int> > ress;

    li sum = 0;

    for (int to: g[v]) {
        ress.push_back(mp(max(dp[to][0] + a[to], dp[to][1]), to));
        sum += ress.back().first;
    }

    dp[v][ress.size() & 1] = sum;

    int i = 0;
    for (int to: g[v]) {
        dp[v][!(ress.size() & 1)] = max(dp[v][!(ress.size() & 1)], sum - ress[i].first + dp[to][0]);
        ++i;
    }
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    g.resize(n);
    dp.resize(n, vector <li>  (2));

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cin >> a[i];
        if (p != -1) {
            --p;
            g[p].push_back(i);
        }
    }

    get(0);
    cout << max(dp[0][0] + a[0], dp[0][1]) << endl;
}