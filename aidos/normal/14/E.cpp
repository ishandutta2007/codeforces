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
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, t;
ll dp[21][4][4][21][21];
ll get(int p, int a, int b, int x, int y){
	if(p == n) {
		return x == t && y == t-1;
	}
	ll &res = dp[p][a][b][x][y];
	if(res != -1) return res;
	res = 0;
	for(int i = 0; i < 4; i++){
		if(i==b) continue;
		int cx = x;
		int cy = y;
		if(b > i && b > a) cx++;
		if(b < i && b < a) cy++;
		res += get(p+1, b, i, cx, cy);
	}
	return res;
}
void solve(){
	cin >> n >> t;
	memset(dp, -1, sizeof dp);
	ll ans = 0;
	for(int i = 0;i < 4; i++){
		for(int j = 0; j < 4; j++) {
			if(i != j) ans += get(2, i, j, 0, 0);
		}
	}
	cout << ans << "\n";
}
int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}