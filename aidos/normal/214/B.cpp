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

const int inf = (1 << 30);

#define MAXN (int) (1e5) + 10
using namespace std;


int a[MAXN];
int b[MAXN];
int dp[MAXN][5];
int n;
int get(int pos, int sum){
    if( pos < 0 ){
        if( sum == 0) return 0;
        return -inf;
    }
    int &res = dp[pos][sum];
    if( res != -1) return res;
    res = get(pos-1, (sum + b[pos]) % 3)+1;
    res= max(res, get(pos-1, sum));
    return res;
}
void calc(int pos, int sum){
    int res = get(pos, sum);
    if( !res ) return ;
    if( get(pos-1, (sum+b[pos]) % 3) + 1 == res){
        cout << b[pos];
        calc(pos-1, (sum + b[pos]) % 3);
        return;
    }
    calc(pos-1, sum);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0;
    while( l < n && a[l] == 0) l++;
    if( l == 0){
        cout << -1 << endl;
        return 0;
    }
    int m = 0;
    for(int i = l; i < n; i++) {
        b[m] = a[i];
        m++;
    }
    n = m;
    if( n == 0){
        cout << 0 << endl;
        return 0;
    }
    memset(dp, -1, sizeof dp);
    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, get(i, 0));
    }
    if( maxi == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = n-1; i >=0; i--){
        if( get(i, 0) == maxi){
            calc(i, 0);
            break;
        }
    }
    for(int i = 0; i < l; i++) cout << 0;





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}