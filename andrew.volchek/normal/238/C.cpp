#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

const int maxn = 3005;

vector<pair<int,int>> g[maxn];

int dpDown[maxn], dpUp[maxn], dpC[maxn];

int root;
int ans = 1e9;

void dfs(int v, int pr = -1) {
    dpDown[v] = dpUp[v] = 0;

    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }

        dfs(to.fst, v);
        dpDown[v] += dpDown[to.fst] + to.snd;
        dpUp[v] += dpUp[to.fst] + 1 - to.snd;
    }

    dpC[v] = dpDown[v];

    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }

        dpC[v] = min(dpC[v], dpC[to.fst] + (dpDown[v] - dpDown[to.fst] - to.snd) + (1 - to.snd));
    }
}


void dfs2(int v, int pr = -1) {
    int s = 0;
    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }

        dfs2(to.fst, v);

        s += dpDown[to.fst] + to.snd;
    }

    for (auto to : g[v]) {
        if (to.fst == pr) {
            continue;
        }

        s -= dpDown[to.fst] + to.snd;
        s += dpC[to.fst] + 1 - to.snd;

        ans = min(ans, s + dpDown[root] - dpDown[v]);

        s -= dpC[to.fst] + 1 - to.snd;
        s += dpDown[to.fst] + to.snd;
    }
}




int main() {
    srand(time(NULL));

    /*while (true)*/
#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(mp(v, 0));
        g[v].pb(mp(u, 1));
    }

    for (int i = 1; i <= n; i++) {
        root = i;
        dfs(i);
        ans = min(ans, dpDown[root]);
        dfs2(i);
    }

    cout << ans << endl;

    return 0;
}