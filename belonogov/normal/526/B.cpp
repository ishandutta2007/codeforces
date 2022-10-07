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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

#define equal equalll
#define less lesss
const int N = 1e5; 
const int INF = 1e9;

int n;
vector < pair < int, int > > e[N];
int sum = 0;

int dfs(int v) {
    if (e[v].empty()) return 0;
    int r1 = dfs(e[v][0].fr) + e[v][0].sc;
    int r2 = dfs(e[v][1].fr) + e[v][1].sc;
    sum += max(r1, r2) - min(r1, r2);
    return max(r1, r2);  
}

void read() {
    scanf("%d", &n); 
    for (int i = 2; i < (1 << (n + 1)); i++) {
        int x;
        scanf("%d", &x);
        e[i / 2].pb(mp(i, x));
    }
    dfs(1);
    cout << sum << endl;
}

void solve() {

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        for (int tt = 0; tt < 1; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}