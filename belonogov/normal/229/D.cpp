#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int maxn = 6000;
const int inf = 1e9;
int a[maxn];
int dp[maxn][maxn];

int main(){
//         freopen("in", "r", stdin);
//         freopen("out", "w", stdout);
    int n, uk, sum;
    cin >> n;
    forn(i, n)
        cin >> a[i];
    
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;    
    forn(i, n){
        uk = i + 1;
        sum = a[i];
        forn(j, n)
            if (dp[i][j] < inf){
    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i]);
    
    while(uk < n && sum < dp[i][j])
        sum += a[uk++];
    if (sum >= dp[i][j]){
        dp[uk][j + uk - i - 1] = min(sum,  dp[uk][j + uk - i - 1]);            
    
    }
            }
    }
    /*forn(i, n + 1){
        forn(j, n + 1)
            cerr << dp[j][i] << " ";
        cerr << endl;
    }
    cerr << endl;
    */for(int i = 0; i < n; i++){
        if (dp[n][i] < inf){
            cout << i << endl;
            cerr << i << endl;
            return 0;
        }
    }
    assert(false);

    return 0;
}