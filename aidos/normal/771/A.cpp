#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, m;
vector<int> g[200200];
map<pii, int> has;
int col[200200];
int sz = 0;
vector<int> comp;

void dfs(int v, int c) {
    col[v] = c;
    comp.pb(v);
    forit (it, g[v]) {
        int to = *it;
        if (col[to] == -1) {
            dfs(to, c);
        }
    }
}

int main(){

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        if (has.count(mp(x, y))) continue;
        has[mp(x, y)] = has[mp(y, x)] = 1;
        g[x].pb(y);
        g[y].pb(x);
    }

    for (int i = 0; i < n; i++) col[i] = -1;

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            comp.clear();
            dfs(i, sz);
            sz++;
            int e = 0;
            for (int j = 0; j < comp.size(); j++) {
                int x = comp[j];
                e += sz(g[x]);
            }
            e /= 2;
            int cur = comp.size();
            if (cur * 1ll * (cur - 1) / 2 != e) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");

    return 0;
}