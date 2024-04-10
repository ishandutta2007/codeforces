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

const int maxn = 1e5 + 5;

int color[maxn];
vector<pair<int,int>> g[maxn];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto to : g[v]) {
            int u = to.fst;
            int c = to.snd;

            if (color[u] == -1) {
                color[u] = c ? color[v] : (1 - color[v]);
            } else {
                if (c && color[v] != color[u]) {
                    cout << 0 << endl;
                    exit(0);
                }

                if (!c && color[v] == color[u]) {
                    cout << 0 << endl;
                    exit(0);
                }
                continue;
            }

            q.push(u);
        }
    }
}

int main() {
    //srand(time(NULL));
    //gen();
    //freopen("a.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    fill(color, color + maxn, -1);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        g[u].pb(mp(v, c));
        g[v].pb(mp(u, c));
    }

    const ll mod = 1000000007;
    ll ans = 1;

    int comp = 0;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            bfs(i);
            comp++;
        }
    }

    for (int i = 0; i < comp - 1; i++) {
        ans = ans * 2 % mod;
    }

    cout << ans << endl;


    return 0;
}