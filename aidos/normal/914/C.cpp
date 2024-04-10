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

using namespace std;
string x;
int k;
int c[1111][1111];
const int mod = 1000*1000*1000+7;
int dp[1111][1111][2];
int d[1111];
int get(int i, int j, int sp){
	if(i == x.size()){
		if(d[j] == k - 1) return 1;
		return 0;
	}
	int &res = dp[i][j][sp];
	if(res != -1) return res;
	res = 0;
	if(sp){
		if(x[i] == '0') {
			res = get(i + 1, j, 1);
		}else if(x[i] == '1'){
			res = (get(i+1, j, 0) + get(i+1, j + 1, 1)) % mod;
		}
	}
	else{
		res = (get(i+1, j, 0) + get(i+1, j + 1, 0)) % mod;
	}
	return res;
}

void solve(){
	cin >> x >> k;
	if(k == 0){
		cout << 1 << endl;
		return;
	}
	for(int i = 0; i < 1010; i++){
		c[i][i] = c[i][0] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
		}
	}
	d[0] = inf;
	d[1] = 0;
	for(int i = 2; i <= 1000; i++){
		d[i] = d[__builtin_popcount(i)] + 1;
	}
	memset(dp, -1, sizeof dp);
	int ans= get(0, 0, 1);
	if(k == 1){
		ans --;
		ans += mod;
		ans %= mod;
	}
	cout << ans << endl;
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}