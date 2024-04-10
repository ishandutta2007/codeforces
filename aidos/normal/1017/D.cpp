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
int a[111];
int n, m, q;
int cost[(1<<13)];
ll dp[1<<13][122];
char tmp[1111];
int cnt[(1<<13)];
void solve(){

	cin >> n >> m >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < (1<<n); i++){
		cost[i] = 0;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)) cost[i] += a[j];
		}
		cost[i] = min(cost[i], 111);
	}
	for(int i = 0; i < m; i++){
		scanf("%s", tmp);
		int d = 0;
		for(int j = 0; j < n; j++){
			if(tmp[j] == '1') d |= (1<<j);
		}
		cnt[d]++;
	}
	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < (1<<n); j++){
			dp[j][cost[((1<<n) - 1)^i^j]] += cnt[i];
		}
	}
	for(int i = 0; i < (1<<n); i++){
		for(int j = 1; j < 111; j++){
			dp[i][j] += dp[i][j-1];
		}
	}
	for(int i = 0; i < q; i++){
		scanf("%s", tmp);
		int d = 0;
		int k;
		scanf("%d", &k);
		for(int j = 0; j < n; j++){
			if(tmp[j] == '1') d |= (1<<j);
		}
		printf("%lld\n", dp[d][k]);
	}
	
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