#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;


ll dp[5055][5055];

int n, k;
int a[300100];
ll b[300300]; 
int len1, len2;

ll get(int l, int r){
    if( l < 0 || r < 0) return (1ll << 55);
    if( l == 0 && r == 0) return 0;
    ll &res=dp[l][r];
    if( res != -1) return res;
    res = (1ll << 55);
    int pos = l * ( len2) + r * ( len1);
    if( l > 0) {
        res = min( res, get(l - 1, r) + a[pos] - a[pos-len2 + 1]);
    }
    if( r > 0){
        res = min( res, get(l, r - 1) + a[pos] - a[pos-len1 + 1]);
    }
    return res;
}



int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    memset(dp, -1, sizeof  dp);
    
    scanf("%d %d\n", &n, &k);

    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    map < int, int > m;
    for(int i = 0; i < k; i++){
        int j = i;
        int ss= 0;
        while( j < n){
            j += k;
            ss++;
        }

        m[ss]++;
    }
    int x= n % k, y = k - n % k;
    len1=n/k;
    len2=len1 + 1;
    cout << get(x, y) <<endl;







    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}