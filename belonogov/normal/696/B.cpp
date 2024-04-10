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
double answer[N];


void read() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int v;
        scanf("%d", &v); v--;
        e[v].pb(i);
    }
}

int sz[N];

void dfs0(int v) {
    sz[v] = 1;
    for (auto u: e[v]) {
        dfs0(u);
        sz[v] += sz[u];
    }
}

void dfs1(int v, double p) {
    p++;
    
    answer[v] = p;
    for (auto u: e[v]) {
        dfs1(u, ((sz[v] - 1) - sz[u]) / 2.0 + p);
    }
}

void solve() {
    dfs0(0);
    dfs1(0, 0);
    
    for (int i = 0; i < n; i++)
        printf("%.17f ", answer[i]);
    puts("");
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