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

const int inf = (1ll << 30) - 1;

#define MAXN (int) (1e7)
using namespace std;

int const mid = 250;
int n;
int dp[111][510];
int t[111], x[111];


int get(int pos, int cur){
    if( cur < 0 || cur >= 2 * mid) return inf;
    if( pos == n){
        if( cur == mid) return 0;
        return inf;
    }
    int &res = dp[pos][cur];
    if( res!=-1) return res;
    res = inf;
    res = min(res, get(pos+1, cur -t[pos]) + t[pos]); 
    res = min(get(pos+1, cur + x[pos]), res);
    return res;
}


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    memset(dp, -1, sizeof dp);
    cin >> n;
    int diff = 0;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> x[i];
        diff += t[i];
    }
    int mini = diff;
    for(int i = 0; i <= diff; i++){
        mini = min(get(0, mid + i), mini);
    }
    cout << mini << endl;

    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}