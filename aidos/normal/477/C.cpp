#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1 << 20);

#define MAXN (int) (1e7)
using namespace std;

string a, b;
int dp[2510];
int d[2010][510];

int dp2[2010][2510];
int dz[510];
int n, m;
void precalc(){
    memset(dp, -1, sizeof dp); 
    memset(dp2, -1, sizeof dp2);
    
    int maxi = 0;
    for(int i=n-1; i>=0; i--){
        if( a[i] == b[0]){
            int k = i;
            int j = 0;
            while( k < n && j < m){
                if( a[k] == b[j]) j++;
                k++;
            }
            if( j == m ) dp[i] = k;
        }
    }

    for(int i = 1; i <= n; i++) dp2[n][i] = inf;
    dp2[n][0] = 0;
    for(int i = n-1; i >= 0; i--){
        dp2[i][0] = 0;
        //cout << i << " " << dp[i] << endl;
        if( dp[i] != -1){
            int x = dp[i];
            int y = dp[i] - i - m;
            for(int j = 1; j<=n; j++){
                dp2[i][j] = min(dp2[x][j-1] + y, dp2[i+1][j]);
            }
        }
        else {
            for(int j = 1; j<= n; j++) dp2[i][j] = dp2[i+1][j];
        }
    }
//    for(int i = 0; i < n; i++){
}

bool check(int x, int y){
    if( dp2[0][x] <= y) return 1;
    return 0;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> a >> b;
    n = a.size();
    m = b.size();
    precalc();
    
    for(int i = 0; i <= n; i++){
        int ans = 0;
        for(int j = 0; j <= n; j++) if( dp2[0][j] <= i && j * m + i <= n) ans = j;
        cout << ans << " ";
    }
//    for(int i = 0; i < min(m, n+1); i++) cout <<"0" <<  " ";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}