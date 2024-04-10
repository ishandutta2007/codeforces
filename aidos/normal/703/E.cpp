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
#include<cassert>
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
#define prev asdfasdfadfasdfzsdfasdf

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int n;
ll k;
ll a[1010];
ll dp[1010][7100];
short prev[1010][7100];
short len[1010][7100];


vector<ll>del;
ll mx = 1e17;
int mx2 = 3000;
void solve(){
	scanf("%d%I64d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%I64d", &a[i]);
	}
	if(k == 1){
		ll mi = mx;
		for(int i = 1; i <= n; i++)
			mi = min(mi, a[i]);
		cout << 1 << endl;
		for(int i = 1; i <= n; i++){
			if(a[i] == mi){
				cout << i << endl;
				return;
		}
			}
		cout << 1 << endl;
		return;
	}
	for(ll i = 1; i  * 1ll * i <= k; i++){
		if(k % i == 0){
			del.pb(i);
			if(i * 1ll * i != k) del.pb(k/i);
		}
	}
	
	sort(all(del));
	int sz=del.size();
	for(int i = 0; i<sz; i++){
		dp[0][i] = mx;
		prev[0][i] = -1;
		len[0][i] = mx2;
	}
	assert(sz < 7100);
	dp[0][sz-1] = 0;
	len[0][sz-1] = 0;
	ll X;
	for(int i = 1; i <= n; i++){
		ll x = __gcd(a[i], k);
		for(int j = 0; j < del.size();j++){
			prev[i][j] = -1;
			dp[i][j] = mx;
			len[i][j] = mx2;
		}
		for(int j = 0; j < del.size(); j++){
			X = lower_bound(all(del), del[j]/__gcd(del[j], x)) - del.begin();
			if(len[i-1][j] + 1 < len[i][X] || (len[i-1][j] + 1 == len[i][X] && dp[i-1][j] + a[i] < dp[i][X]) ){
				dp[i][X] = dp[i-1][j] + a[i];
				len[i][X] = len[i-1][j] +1;
				prev[i][X] = i;
				
			}
		}
		for(int j = 0; j < del.size(); j++){
			if(len[i][j] > len[i-1][j] || (len[i][j] == len[i-1][j] && dp[i][j] > dp[i-1][j])){
				prev[i][j] = i-1;
				dp[i][j] = dp[i-1][j];
				len[i][j] = len[i-1][j];
			}
		}
	} 
	
	if(dp[n][0]>=mx){
		cout << -1 <<endl;
		return;
	}
	int ind = n;
	int xx = 0;
	vector<int> ans;
	while(ind > 0){
		if(prev[ind][xx] == ind){
			int new_xx = -1;
			for(int i = 0; i < del.size(); i++){
				X = lower_bound(all(del), del[i]/__gcd(del[i], a[ind])) - del.begin();
				if(xx == X && dp[ind-1][i] + a[ind] == dp[ind][xx] && len[ind-1][i] + 1== len[ind][xx]){
					new_xx = i;
				}
			}
			assert(new_xx>=0);
			ans.pb(ind);
			ind--;
			xx = new_xx;
		}else {
			ind--;
		}
	}
	printf("%d\n", ans.size());
	ll t = k;
	for(int i = 0; i < ans.size(); i++){
		if(i) printf(" ");
		printf("%d", ans[i]);
		t = t/__gcd(a[ans[i]], t);
	}
	assert(t==1);
	printf("\n");
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}