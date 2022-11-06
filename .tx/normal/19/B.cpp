#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <time.h>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(stt) for (int i = 0; i < stt; ++i)
#define foj(stt) for (int j = 0; j < stt; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

ll dp[2001][4002];
int t[2000];
int c[2000];

const ll inf = 1e16;

// File names!!!

int main() {
    // openfiles("test");
    int n;
    sci(n);
    foi(n) scii(t[i], c[i]);

    foi(2001) foj(4002) dp[i][j] = inf;
    dp[0][2001] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 4001; j++) {
            dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
            dp[i + 1][min(4001, j + t[i])] = min(dp[i + 1][min(4001, j + t[i])], dp[i][j] + c[i]);
        }
    }

    ll ans = inf;
    for (int i = 2001; i <= 4001; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;

    
    return 0;
}