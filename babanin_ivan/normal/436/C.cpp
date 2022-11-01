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

int n, m, k, w;
char c[1100][11][11];

vector <pair <int, pair <int, int> > > g;
int par[1100];

int getanc(int x) {
    if (par[x] != x)
        return par[x] = getanc(par[x]);
    return x;
}

void uni(int x, int y) {
    int a = getanc(x);
    int b = getanc(y);
    if (rand() & 1)
        swap(a, b);
    par[a] = b;
}

vector <vector <int> > gg;

void dfs(int v, int p) {
    if (p != -1)
        cout << v << " " << p << "\n";
    for (int i = 0; i < gg[v].size(); ++i) {
        int to = gg[v][i];
        if (to != p) {
            dfs(to, v);
        }
    }
}

void solve() {
    cin >> n >> m >> k >> w;
    for (int i = 1; i <= k; ++i) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                cin >> c[i][x][y];
            }
        }
    }
    for (int i = 0; i <= k; ++i)
        par[i] = i;
    gg.resize(k + 1);
    for (int i = 1; i <= k; ++i)
        g.push_back(mp(n * m, mp(0, i)));
    for (int i = 1; i <= k; ++i)
        for (int j = i + 1; j <= k; ++j) {
            int sum = 0;
            for (int x = 0; x < n; ++x)
                for (int y = 0; y < m; ++y) {
                    if (c[i][x][y] != c[j][x][y])
                        ++sum;
                }
            g.push_back(mp(sum * w, mp(i, j)));
        }
    sort(g.begin(), g.end());
    int sum = 0;
    for (int i = 0; i < g.size(); ++i) {
        if (getanc(g[i].second.first) != getanc(g[i].second.second)) {
            sum += g[i].first;
            uni(g[i].second.first, g[i].second.second);
            gg[g[i].second.first].push_back(g[i].second.second);
            gg[g[i].second.second].push_back(g[i].second.first);
        }
    }
    cout << sum << endl;
    dfs(0, -1);
}