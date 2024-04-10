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
const int N = 3333;
const long long INF = 1e18 + 19;

int n;
int a[N];
long long dp[N][N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        a[i] -= i;
    vector < int > b;
    for (int i = 0; i < n; i++)
        b.pb(a[i]);
    sort(b.begin(), b.end());
    b.resize(unique(all(b)) - b.begin());

    memset(dp, 63, sizeof(dp)); 
    //cerr << "b: ";
    //for (auto x: b)
        //cerr << x << " ";
    //cerr << endl;
    //cerr << "a: ";
    //for (int i = 0; i < n; i++)
        //cerr << a[i] << " ";
    //cerr << endl;

    for (int i = 0; i < (int)b.size(); i++)
        dp[0][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)b.size(); j++)  {
            if (j > 0 && i != 0) {
                if (b[j] <= a[i - 1]) {
                    //db2("k3", dp[1][1]);
                    //db2(b[j], a[i]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] - (b[j] - b[j - 1]));
                    //db2("k2", dp[1][1]);
                }
                else 
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + (b[j] - b[j - 1]));
            }
            //dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + max(0, b[j] - a[i]));
            //db2("k0", dp[3][3]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + abs(b[j] - a[i]));
            //db2("k1", dp[3][3]);
        }
    }
    /*for (int i = 0; i <= n; i++, cerr << endl) {
        cerr << i << ": ";
        for (int j = 0; j <= n; j++)
            epr("%02lld ", dp[i][j]);
            //cerr << dp[i][j] << " ";
    }*/
    long long mn = INF;
    for (int j = 0; j < (int)b.size(); j++) {
        long long sub = 0;
        if (b[j] < a[n - 1])
            sub = a[n - 1] - b[j];
        mn = min(mn, dp[n][j] - sub);
    }

    cout << mn << endl;

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