#include <cstdio>
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
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
#define dbg(x) { cerr << #x << " = " << x << endl; }
const int N = 2e3 + 10;
const int INF = 1e9;

int n, m;
int w[N];
int a[N];
bool use[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

}

void solve() {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        memset(use, 0, sizeof(use));
        for (int j = i - 1; j >= 0 && a[j] != a[i]; j--) {
            if (use[a[j]] == 0) {
                use[a[j]] = 1;
                ans += w[a[j]];
            }
        } 
    }
    printf("%d\n", ans);
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