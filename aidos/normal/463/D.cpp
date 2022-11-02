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

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;

bool a[1001][1001];
int n, k;
int po[6][1001];
int dp[1001];
int get(int x){
    int &res = dp[x];
    if( res!= -1) return res;
    res = 1;
    for(int i = 0; i < n; i++){
        if(a[x][i]) res=max(res, get(i) + 1);
    }
    return res;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        for(int j = 0, x; j < n; j++){
            cin >> x;
            x--;
            po[i][x] = j;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool &ok = a[i][j];
            ok = 1;
            for(int t = 0; t < k; t++){
                if(po[t][j] <= po[t][i]) ok = 0;
            }
        }
    }
    memset(dp, -1, sizeof dp);
    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, get(i));
    }
    cout <<maxi << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}