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
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9;


int n, m;
int h[N];
int d[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &d[i], &h[i]);
    } 
}

void solve() {
    int mx = 0;
    mx = max(h[0] + d[0] - 1, n - d[m - 1] + h[m - 1]);
    for (int i = 0; i < m - 1; i++) {
        int dx = d[i + 1] - d[i];
        int dh = abs(h[i + 1] - h[i]);
        if (dx < dh) {
            printf("IMPOSSIBLE\n");
            return;
        }
        dx -= dh;
        mx = max(mx, max(h[i + 1], h[i]) + dx / 2);
    } 
    printf("%d\n", mx);
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
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
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