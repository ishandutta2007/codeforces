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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n;
vector < int > e[N];
bool use[N];
int sz[N];
vector < int > c;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
}

void dfs0(int v) {
    use[v] = 1;
    sz[v] = 1;
    int mx = 0;
    for (auto u: e[v]) {
        if (!use[u]) {
            dfs0(u);
            sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
    }
    mx = max(mx, n - sz[v]);
    if (mx * 2 <= n)
        c.pb(v);
}


void printAns(vector < int > a) {
    for (auto x: a)
        printf("%d ", x);
    puts("");
    exit(0);
}

void dfs1(int v) {
    use[v] = 1;
    sz[v] = 1;
    for (auto u: e[v]) {
        if (use[u]) continue;
        dfs1(u);
        sz[v] += sz[u];
    }
}

multiset < int > all;
vector < int > answer;

void dfs2(int v) {
    use[v] = 1;
    for (auto u: e[v]) {
        if (!use[u])
            dfs2(u);
    }
    int up = n - sz[v];    
    assert(up * 2 > n);
    int need = up - n / 2;
    if (*all.rbegin() >= need) 
        answer[v] = 1;
}


void solve() {
    dfs0(0);
    if (c.size() == 2) {
        printAns(vector < int > (n, 1)); 
        return;
    }
    assert(c.size() == 1);
    memset(use, 0, sizeof(use));
    int head = c[0];
    dfs1(head);
    
    for (auto u: e[head]) {
        all.insert(sz[u]);
    }


    answer.resize(n, 0);
    answer[head] = 1;
    memset(use, 0, sizeof(use));
    use[head] = 1;
    for (auto u: e[head]) {
        all.erase(all.find(sz[u]));
        dfs2(u);
        all.insert(sz[u]);
    }


    printAns(answer);

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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