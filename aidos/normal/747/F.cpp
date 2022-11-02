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

int k, t;
ll dp[111][25];
ll C[155][155];
ll getLen(int len){
	memset(dp, 0, sizeof dp);
	for(int i = 0; i <= t; i++){
		dp[i][0] = 1;
	}

	for(int j = 1; j < 15; j++){
		for(int i = 0; i <= len; i++){
			for(int k = 0; k <= min(t, i); k++){
				dp[i][j] += dp[i-k][j-1] * C[i][k];
			}
		}
	}
	dp[len][15] = dp[len][14];
	for(int i = 1; i <= t; i++){
		int x = len - i;
		if(x <= 0) continue;
		dp[len][15] += dp[len - i][14] * C[len - 1][i];
	}
	return dp[len][15];
}
int n;
vector<int> cur;
int cnt[111];

ll calc(){
	if(cur[0] == 0) return 0;
	memset(dp, 0, sizeof dp);
	for(int i = 0; i < 16; i++)
		cnt[i] = 0;
	for(int i = 0; i < cur.size(); i++){
		cnt[cur[i]]++;
	}
	for(int i = 0; i < 16; i++){
		if(cnt[i] > t) return 0;
		cnt[i] = t - cnt[i];
	}
	int len = n - cur.size();
	for(int i = 0; i <= cnt[0]; i++){
		dp[i][0] = 1;
	}
	for(int j = 1; j < 16; j++){
		for(int i = 0; i <= len; i++){
			for(int k = 0; k <= cnt[j]; k++){
				if(i < k) continue;
				dp[i][j] += dp[i-k][j-1] * C[i][k];
			}
		}
	}
	return dp[len][15];
}
void go(int pos, int &k){
	if(pos == n) return;
	for(int i = 0; i < 16; i++){
		cur.pb(i);
		ll cc = calc();
		if(cc >= k){
			go(pos + 1, k);
			return;
		}
		cur.pop_back();
		k -= cc;
	}	
}
void solve(){
	scanf("%d%d", &k, &t);
	for(int i = 0; i < 150; i++){
		for(int j = 1; j < i; j++)
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		C[i][0] = 1;
		C[i][i] = 1;
	}
	n = -1;
	for(int i = 1;  ; i++){
		ll x = getLen(i);
		if(x >= k){
			n = i;
			break;
		}
		k-=x;
	}
	go(0, k);
	for(int i = 0;  i< n; i++){
		if(cur[i] < 10) printf("%d", cur[i]);
		else printf("%c", cur[i] - 10 + 'a');
	}
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