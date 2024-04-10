/*#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>*/

#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 1e5;
const int INF = 1e9;

int n;
int d[N];
int s[N];
int T;
queue < int > q;
vector < pair < int, int > > edge;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &d[i], &s[i]);
    for (int i = 0; i < n; i++)
        T += d[i];
    assert(T % 2 == 0);
    T /= 2;
}

void solve() {
    for (int i = 0; i < n; i++)
        if (d[i] == 1) {
            q.push(i);
        }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        assert(d[v] <= 1);
        if (d[v] == 0) continue;
        int u = s[v];
        edge.pb(mp(v, u));
        s[v] = 0;
        d[v]--;
        d[u]--;
        s[u] ^= v;
        if (d[u] == 1)
            q.push(u);
    }
}

void printAns() {
    assert(T == (int)edge.size());  
    printf("%d\n", (int)edge.size());
    for (auto x: edge)
        printf("%d %d\n", x.fr, x.sc);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}