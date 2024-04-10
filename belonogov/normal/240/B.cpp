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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 222;
const long long INF = 1e9 + 19;


int n, a, b;
int dpA[N][N * N];
int dpB[N][N * N];
int h[N];
int pref[N];

void read() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);
}

void upd(int & a, int b) {
    a = min(a, b);
}

void solve() {
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + h[i];
    
    memset(dpA, 63, sizeof(dpA));
    memset(dpB, 63, sizeof(dpB));
    dpA[0][0] = 0;
    dpB[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int hPrev = (i == 0)? 0: h[i - 1];
        for (int usedA = 0; usedA <= a; usedA++) {
            int haveA = a - usedA;
            int haveB = b - (pref[i] - usedA);
            if (haveA >= h[i])  {
                upd(dpA[i + 1][usedA + h[i]], dpB[i][usedA] + min(h[i], hPrev));
                upd(dpA[i + 1][usedA + h[i]], dpA[i][usedA]);
            }
            if (haveB >= h[i]) {
                upd(dpB[i + 1][usedA], dpA[i][usedA] + min(h[i], hPrev));
                upd(dpB[i + 1][usedA], dpB[i][usedA]);
            }
        }
    }
    int mn = INF;
    for (int i = 0; i <= a; i++) {
        mn = min(mn, dpA[n][i]);
        mn = min(mn, dpB[n][i]);
    }
    if (mn == INF)
        puts("-1");
    else
        printf("%d\n", mn);
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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