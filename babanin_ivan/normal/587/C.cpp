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

int n, m, q;

vector <vector <int> > g;

vector <int> depth;

const int log_n = 18;

vector <vector <int> > anc;
vector <vector <vector <int> > > panc;

vector <vector <int> > people;

const int E = 10;

void norma(vector <int>& x, int G=E) {
    sort(x.begin(), x.end());
    while (x.size() > G) {
        x.pop_back();
    }
}

void dfs(int v, int p = -1) {
    if (p != -1) {
        depth[v] = depth[p] + 1;
    }

    norma(people[v]);

    anc[v].resize(log_n);
    panc[v].resize(log_n);

    if (p != -1) {
        anc[v][0] = p;
        panc[v][0] = people[v];

        for (int i = 1; i < anc[v].size(); ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
            panc[v][i] = panc[v][i - 1];
            for (int d : panc[anc[v][i - 1]][i - 1]) {
                panc[v][i].push_back(d);
            }
            norma(panc[v][i]);
        }
    }
    else {
        for (int i = 0; i < anc[v].size(); ++i) {
            panc[v][i] = people[v];
        }
    }

    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}


int go_up(int v, int d) {
    for (int i = 0; i < log_n; ++i) {
        if ((1 << i) & d) {
            v = anc[v][i];
        }
    }
    return v;
}

void upd(vector <int>& x, vector <int> y) {
    for (int z : y) {
        x.push_back(z);
    }
}

int lca(int x, int y) {
    if (depth[x] > depth[y]) {
        swap(x, y);
    }
    y = go_up(y, depth[y] - depth[x]);
    if (x == y) {
        return x;
    }
    for (int i = log_n - 1; i >= 0; --i) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

void solve() {
    cin >> n >> m >> q;
    g.resize(n);
    depth.resize(n);
    anc.resize(n);
    people.resize(n);
    panc.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
            --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        people[x].push_back(i);
    }

    dfs(0);


    for (int i = 0; i < q; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        --x;
        --y;
        int gg = lca(x, y);

        vector <int> result;

        if (gg == x || gg == y) {
            int z = -gg + x + y;
            
            int curv = z;

            for (int i = log_n - 1; i >= 0; --i) {
                if ((depth[z] - depth[gg]) & (1 << i)) {
                    upd(result, panc[curv][i]);
                    curv = anc[curv][i];
                }
            }
            
        }
        else {
            int curv = x;

            for (int i = log_n - 1; i >= 0; --i) {
                if ((depth[x] - depth[gg]) & (1 << i)) {
                    upd(result, panc[curv][i]);
                    curv = anc[curv][i];
                }
            }
            curv = y;

            for (int i = log_n - 1; i >= 0; --i) {
                if ((depth[y] - depth[gg]) & (1 << i)) {
                    upd(result, panc[curv][i]);
                    curv = anc[curv][i];
                }
            }
        }
        upd(result, people[gg]);

        norma(result, t);
        cout << result.size() << " ";
        for (int u : result) {
            cout << u + 1 << " ";
        }
        cout << "\n";
    }
}