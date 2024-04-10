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
const int N = 1111;
const long long INF = 1e9 + 19;


int n, m;
int a[N][N];
int b[N][N];
int dp1[N][N];
int dp2[N][N];
int dp3[N][N];
int dp4[N][N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void upd(int & a, int b) {
    a = max(a, b);
}

void solve() {
    dp1[0][0] = a[0][0];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            upd(dp1[i + 1][j], dp1[i][j] + a[i + 1][j]);
            upd(dp1[i][j + 1], dp1[i][j] + a[i][j + 1]);
        }
    dp2[0][m - 1] = a[0][m - 1];
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--) {
            upd(dp2[i + 1][j], dp2[i][j] + a[i + 1][j]);
            if (j > 0)
                upd(dp2[i][j - 1], dp2[i][j] + a[i][j - 1]);
        }
    dp3[n - 1][0] = a[n - 1][0];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++) {
            if (i > 0) upd(dp3[i - 1][j], dp3[i][j] + a[i - 1][j]);
            upd(dp3[i][j + 1], dp3[i][j] + a[i][j + 1]);
        }
    dp4[n - 1][m - 1] = a[n - 1][m - 1];
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            if (i > 0) upd(dp4[i - 1][j], dp4[i][j] + a[i - 1][j]);
            if (j > 0) upd(dp4[i][j - 1], dp4[i][j] + a[i][j - 1]); 
        }



    int mx = 0;
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < m; j++) {
            mx = max(mx, dp1[i][j - 1] + dp4[i][j + 1] + dp2[i - 1][j] + dp3[i + 1][j]);
            mx = max(mx, dp1[i - 1][j] + dp4[i + 1][j] + dp2[i][j + 1] + dp3[i][j - 1]);
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mx = max(mx, b[i][j]);

    printf("%d\n", mx);
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