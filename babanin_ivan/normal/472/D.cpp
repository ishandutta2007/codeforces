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
    //ios_base::sync_with_stdio(false);
    //cout << fixed;
    //cout.precision(10);
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

void printerr() {
    cout << "NO\n";
    exit(0);
}

vector <vector <pair <int, int> > > g;
vector <int> d;

void dfs(int v, int cur, int p = -1) {
    d[v] = cur;
    if (d[v] > 1000000000) {
        printerr();
    }

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i].first;
        if (to != p) {
            dfs(to, cur + g[v][i].second, v);
        }
    }
}

void check(int v, vector <int>& t) {
    dfs(v, 0);

    for (int i = 0; i < g.size(); ++i) {
        if (d[i] != t[i])
            printerr();
    }
}

vector <int> p;

int getAnc(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = getAnc(p[v]);
}

void uni(int x, int y) {
    int a = getAnc(x);
    int b = getAnc(y);
    p[a] = b;
}

void solve() {
    int n;
    scanf("%d", &n);
    g.resize(n);
    p.resize(n);
    d.resize(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    vector <vector <int> > a(n, vector <int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
        scanf("%d", &a[i][j]);
        }

    vector <pair <int, pair <int, int> > > b;

    for (int i = 0; i < n; ++i) {
        if (a[i][i]) {
            printerr();
        }

        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[j][i]) {
                printerr();
            }
            if (i != j && !a[i][j]) {
                printerr();
            }
            if (i < j)
                b.push_back(mp(a[i][j], mp(i, j)));
        }
    }
    
    sort(b.begin(), b.end());

    for (int i = 0; i < b.size(); ++i) {
        if (getAnc(b[i].second.first) != getAnc(b[i].second.second)) {
            uni(b[i].second.first, b[i].second.second);
            g[b[i].second.first].push_back(mp(b[i].second.second, b[i].first));
            g[b[i].second.second].push_back(mp(b[i].second.first, b[i].first));
        }
    }

    for (int i = 0; i < n; ++i)
        check(i, a[i]);
    cout << "YES\n";
}