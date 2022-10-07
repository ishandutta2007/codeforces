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
const int N = 111;
const int INF = 1e9 + 19;

int n;
long long k;

void read() {
    cin >> n >> k;
    k--;
}

long long dp[N];

void solve() {
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 2] + dp[i - 1];
   
    //for (int i = 0; i <= n; i++)
        //cerr << dp[i] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        if (k >= dp[n - i - 1]) {
            k -= dp[n - i - 1];
            printf("%d %d ", i + 2, i + 1);
            i++;
        }
        else  {
            printf("%d ", i + 1);
        }
    }
    assert(k == 0);

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