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
const int maxn = (int) 1e5 + 10;

using namespace std;

int v1, v2, d, t;
int dp[111][5000];
bool ok[111][5000];
int get(int x, int v){
	if( v < 0) return -100000000;
	if(x == t-1) {
		if(v == v2) return v;
		return -100000000;
	}
	if(ok[x][v]) return dp[x][v];
	ok[x][v] = 1;
	dp[x][v] = -100000000;
	for(int i = -d; i <= d; i++){
		dp[x][v] = max(get(x+1, v+i) + v, dp[x][v]);
	}
	return dp[x][v];
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif


    cin >> v1 >> v2 >> t >> d;

    cout << get(0, v1) << endl;



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}