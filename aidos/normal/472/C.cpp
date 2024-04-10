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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1 << 30);
const int maxn = 1 << 17;

using namespace std;

int n;
string S[maxn][3];
int p[maxn];
int dp[3][maxn];

int get(int k, int t){
    if( k == n-1) return 1;
    int &res = dp[t][k];
    if( res !=-1) return res;
    if( S[p[k]][t] < S[p[k+1]][0] && get(k+1, 0) ) res = 1;
    else if( S[p[k]][t] < S[p[k+1]][1] && get(k+1, 1) ) res = 1;
    else res = 0;
    return res;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> S[i][0] >> S[i][1];
    }
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    memset(dp, -1, sizeof(dp));

    if( get(0 , 0 ) || get(0, 1) ) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}