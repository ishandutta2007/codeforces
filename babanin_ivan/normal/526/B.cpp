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
    while (t--) {
        //++timer;
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

    int n, m;
    vector <int> a;
    vector <int> b;

int dfs(int v, int sum) {
    if (v >= (1 << n)) {
        b.push_back(sum);
        return sum;
    }
    

    return max(dfs(2 * v, sum + a[2 * v]), dfs(2 * v + 1, sum + a[2 * v + 1]));
}

int xx;
int ans = 0;

void get(vector <int> b) {
    if (b.size() == 1) {
        return;
    }
    vector <int> c[2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < b.size() / 2; ++j) {
            c[i].push_back(b[j + i * (b.size() / 2)]);
        }
        int x = c[i].back();
        for (int j = 0; j < c[i].size(); ++j) {
            x = max(x, c[i][j]);
        }
        ans += xx - x;
        for (int j = 0; j < c[i].size(); ++j) {
            c[i][j] += xx - x;
        }
    }
    get(c[0]);
    get(c[1]);
}

void solve() {

    cin >> n;
    m = (1 << (n + 1)) - 1;
    a.resize(m + 1);
    for (int i = 2; i <= m; ++i) {
        cin >> a[i];
    }
    
    xx = dfs(1, 0);

    get(b);
    cout << ans << endl;
}