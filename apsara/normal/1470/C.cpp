#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 300100;
int a[V], b[V];

int n, K, x;
int Q = 2;

void mov() {
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
        int l = (i - 2 + n) % n + 1;
        int r = i % n + 1;
        if (i == Q) l = r;
        b[l] += a[i] / 2;
        b[r] += (a[i] + 1) / 2;
    }
    for (int i = 1; i <= n; ++i) a[i] = b[i];
}

void PT() {for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");}

void solve() {
    for (int i = 1; i <= n; ++i) a[i] = K;
    //for (int i = 0; i < 20; ++i) {PT();mov();}return;
    int cur = n;
    int step = 0;
    while (1) {
        //PT();
        printf("? %d\n", cur);
        fflush(stdout);
        scanf("%d", &x);
        if (x != K) {
            break;
        } else {
            ++step;
            cur = (cur - step + n) % n;
            if (cur == 0) cur = n;
        }
        //mov();
    }
    int d = 1;
    if (x > K) d = -1;
    while (1) {
        //PT();
        printf("? %d\n", cur);
        fflush(stdout);
        scanf("%d", &x);
        if (x == K) {
            //int ans = (cur - 1 - step + n + n) % n;
            //if (ans == 0) ans = n;
            int ans = cur;
            printf("! %d\n", ans);
            fflush(stdout);
            break;
        } else {
            cur = (cur + d) % n;
            if (cur == 0) cur = n;
            ++step;
        }
        //mov();
    }
}

int main() {
    while (~scanf("%d%d", &n, &K)) {
        solve();
    }
    return 0;
}

/*

*/