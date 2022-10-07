#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 2e6 + 10;
const long long INF = 1e9 + 19;

int n, m;
vector < vector < int > > a;
vector < int > e[N];
int p[N];
int tmr;
int pos[N];
int ver[N];
bool use[N];
vector < int > st;
int val[N];

void read() {
    scanf("%d%d", &n, &m);
    a.resize(n, vector < int > (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

int getColor(int v) {
    return (p[v] == v)? v: p[v] = getColor(p[v]);
}

void merge(int v, int u) {
    v = getColor(v);
    u = getColor(u);
    p[v] = u;
}

void dfs(int v) {
    use[v] = 1;
    for (auto u: e[v])
        if (!use[u])
            dfs(u);
    st.pb(v);
}

int getId(int i, int j) {
    return i * m + j;
}

void solve() {
    vector < int > xx;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            xx.pb(a[i][j]); 
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = lower_bound(xx.begin(), xx.end(), a[i][j]) - xx.begin();

    for (int i = 0; i < n * m; i++)
        p[i] = i; 

    for (int i = 0; i < n; i++) {
        tmr++;
        for (int j = 0; j < m; j++) {
            int x = a[i][j];
            if (ver[x] == tmr) {
                merge(pos[x], getId(i, j));
            }
            ver[x] = tmr;
            pos[x] = getId(i, j);
        }
    }

     
    for (int j = 0; j < m; j++) {
        tmr++;
        for (int i = 0; i < n; i++) {
            int x = a[i][j];
            if (ver[x] == tmr) {
                merge(pos[x], getId(i, j));
            }
            ver[x] = tmr;
            pos[x] = getId(i, j);
        }
    }

    for (int i = 0; i < n; i++)  {
        vector < pair < int, int > > g;
        for (int j = 0; j < m; j++) {
            g.pb(mp(a[i][j], getColor(getId(i, j))));
        }
        sort(g.begin(), g.end());
        for (int j = 0; j < (int)g.size() - 1; j++)
            if (g[j].fr == g[j + 1].fr)
                assert(g[j].sc == g[j + 1].sc);
        g.resize(unique(g.begin(), g.end()) - g.begin());

        for (int j = 0; j < (int)g.size() - 1; j++) {
            e[g[j + 1].sc].pb(g[j].sc);
        }
    }


    for (int j = 0; j < m; j++)  {
        vector < pair < int, int > > g;
        for (int i = 0; i < n; i++) {
            g.pb(mp(a[i][j], getColor(getId(i, j))));
        }
        sort(g.begin(), g.end());
        for (int k = 0; k < (int)g.size() - 1; k++)
            if (g[k].fr == g[k + 1].fr)
                assert(g[k].sc == g[k + 1].sc);
        g.resize(unique(g.begin(), g.end()) - g.begin());

        for (int k = 0; k < (int)g.size() - 1; k++) {
            e[g[k + 1].sc].pb(g[k].sc);
        }
    }

    for (int i = 0; i < n * m; i++) {
        if (p[i] == i && !use[i])
            dfs(i); 
    } 

    memset(val, -1, sizeof(val));

    for (auto v: st) {
        int mx = -1;
        for (auto u: e[v])
            mx = max(mx, val[u]);
        val[v] = mx + 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = val[getColor(getId(i, j))];

    
    
    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j] + 1);

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}