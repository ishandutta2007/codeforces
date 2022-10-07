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

#define equal equalll
#define less lesss
const int N = 2222;
const int INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n, sum;
int a[N];
int c[N][N];
int dp[N];
int pref[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
}

void solve() {
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    c[0][0] = 1;
    for (int i = 0; i < sum; i++)
        for (int j = 0; j <= i; j++) {
            c[i + 1][j] = (c[i + 1][j] + c[i][j]) % MOD;
            c[i + 1][j + 1] = (c[i + 1][j + 1] + c[i][j]) % MOD;
        }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            //db2(pref[i] + j, j);
            dp[i + 1] = (dp[i + 1] + dp[i] * 1ll * c[pref[i] - 1 + j][j]) % MOD;
        }
    }
    //for (int i = 0; i <= n; i++)
        //cerr << dp[i] << " ";
    //cerr << endl;
    cout << dp[n] << endl; 



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