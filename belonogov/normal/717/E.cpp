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
#include <random>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int color[N];
vector<int> e[N];
vector<int> answer;
int has[N];

void dfs0(int v, int par) {
    if (color[v] == -1)
        has[v] = 1;
    for (auto u: e[v]) {
        if (u == par) continue;
        dfs0(u, v);
        has[v] |= has[u];
    }
}

void add(int x) {
    answer.pb(x);
    color[x] *= -1;
}

void dfs1(int v, int par) {
    for (auto u: e[v]) {
        if (par == u) continue;
        if (has[u]) {
            add(u);
            dfs1(u, v);
            add(v);
        }
    }
    if (color[v] == -1)  {
        if (par == -1) {
            int ch = e[v][0];
            add(ch);
            add(v);
            add(ch);
        }
        else {
            add(par);
            add(v);
        }
    }
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &color[i]);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }

    dfs0(0, -1);
    answer.pb(0);
    dfs1(0, -1);

    for (int i = 0; i < n; i++)
        assert(color[i] == 1);
    for (auto x: answer) {
        printf("%d ", x + 1);
    }    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}