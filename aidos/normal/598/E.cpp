#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

int dp[35][35][55];
int get(int n, int m, int k){
    if(n * m < k) return 10000100;
    if(k == 0 || n * m == k) return 0;
    int &res = dp[n][m][k];
    if(res != -1) return res;
    res = 10000100;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            res=min(res, get(i, m, j) + get(n-i, m, k - j)+ m * m);
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 0; j <= k; j++){
            res=min(res, get(n, i, j) + get(n, m - i, k - j)+ n * n);
        }
    }
    return res;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    memset(dp, -1, sizeof dp);
    int t, n, m, k;
    scanf("%d", &t);
    for(int i=0; i < t; i++){
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", get(n, m, k));
    }

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}