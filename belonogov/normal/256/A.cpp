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
const int N = 4444;
const long long INF = 1e9 + 19;


int dp[N][N];
int dp1[N];
int a[N];
int n;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    vector < int > xx;
    for (int i = 0; i < n; i++)
        xx.pb(a[i]);
    sort(xx.begin(), xx.end());

    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

    for (int i = 0; i < n; i++)
        a[i] = lower_bound(xx.begin(), xx.end(), a[i]) - xx.begin();

    int m = xx.size();
    for (int i = 0; i < n; i++) {
        memset(dp1, 0, sizeof(dp1));
        int x = a[i];
        for (int j = 0; j < i; j++) {
            int y = a[j];
            dp1[y] = max(2, dp[y][x] + 1);
        }
        for (int j = 0; j < m; j++)
            dp[x][j] = max(dp[x][j], dp1[j]);
    } 

    int answer = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer = max(answer, dp[i][j]);

    printf("%d\n", answer);
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
        }
    }
    else {
        stress();
    }

    return 0;
}