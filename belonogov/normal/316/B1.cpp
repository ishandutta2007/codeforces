#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1e3 + 10;
const int inf = 1e9;

bool dp[maxn][maxn];
vector < int > a;
int next[maxn];
bool use[maxn];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    for (int i = 0; i < n; i++) {
        scanf("%d", &next[i]);
        next[i]--;
        use[next[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            int d = -1;
            int cnt = 0;
            for (int j = i; j != -1; j = next[j], cnt++)
                if (j == k) {
                    d = cnt;
                }
            if (d != -1) {
                dp[0][cnt - d] = 1;
            }
            else {
                a.pb(cnt);
            }
        }
    }
    for (int i = 0; i < (int)a.size(); i++)
        for (int j = 0; j <= n; j++)
            if (dp[i][j]) {
                dp[i + 1][j] = 1; 
                dp[i + 1][j + a[i]] = 1;
            }
    for (int i = 0; i <= n; i++)
        if (dp[(int)a.size()][i])
            printf("%d\n", i);
    return 0;
}