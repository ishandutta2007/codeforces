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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 10055;
const long long INF = 1e18 + 19;

int n;
int x;
int l[N];
int r[N];
long long dp[2][N];
vector < int > zx;

void read() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }

}

void upd(long long & a, long long b) {
    a = min(a, b);
}

int distToSeg(int pos, int id) {
    if (l[id] <= pos && pos <= r[id]) return 0;
    return min(abs(zx[pos] - zx[l[id]]), abs(zx[pos] - zx[r[id]]));
}


void solve() {
    zx.pb(x);
    for (int i = 0; i < n; i++) {
        zx.pb(l[i]);
        zx.pb(r[i]);
    }
    sort(all(zx));
    zx.resize(unique(all(zx)) - zx.begin());
    x = lower_bound(all(zx), x) - zx.begin();
    for (int i = 0; i < n; i++) {
        l[i] = lower_bound(all(zx), l[i]) - zx.begin();
        r[i] = lower_bound(all(zx), r[i]) - zx.begin();
    }
    int m = zx.size();
    for (int j = 0; j < m; j++)
        dp[0][j] = INF;
    dp[0][x] = 0;

    //db(m);
    //for (int i = 0; i < m; i++)
        //db2(i, zx[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            dp[1][j] = INF;

        for (int j = l[i]; j <= r[i]; j++) {
            upd(dp[1][j], dp[0][j]);
        }
        long long mn = INF;
        for (int j = 0; j <= l[i]; j++) {
            upd(mn, dp[0][j] + abs(zx[j] - zx[l[i]]));
            upd(dp[1][j], mn);
        }
        mn = INF;
        for (int j = m - 1; j >= r[i]; j--) {
            upd(mn, dp[0][j] + abs(zx[j] - zx[r[i]]));
            upd(dp[1][j], mn);
        }

        memcpy(dp[0], dp[1], sizeof(dp[1]));
    }
    //for (int j = 0; j < m; j++)
        //cerr << dp[0][j] << " ";
    //cerr << endl;

    long long mn = INF;
    for (int i = 0; i < m; i++)
        upd(mn, dp[0][i]);
    cout << mn << endl;


    


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