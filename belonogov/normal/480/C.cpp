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
const int N = 5555;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n, a, b, k;
int dp[N][N];
long long pref[N];

void read() {
    scanf("%d%d%d%d", &n, &a, &b, &k); 
    if (b < a) {
        a -= b;
        a--;
        n -= b;
    } 
    else {
        n = b - 1;
        a = b - a - 1; 
    }

}

void solve() {
    dp[0][a] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++)
            pref[j + 1] = (pref[j] + dp[i - 1][j]) % MOD;
        for (int j = 0; j < n; j++) {
            int l = (j + 1) / 2; 
            dp[i][j] = (pref[n] - pref[l] + MOD - dp[i - 1][j] + MOD) % MOD;
        }
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum = (sum + dp[k][i]) % MOD;
    cout << sum << endl;

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