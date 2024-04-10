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
int n;
ll t;
pair<ll,int> a[200200];
ll c[200200];
ll lw[200200];
ll d[200200];
int k[200200];

int dp[200200];

void solve(){
	scanf("%d%lld", &n, &t);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i].f);
		a[i].f+=t;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].s);
		a[i].s --;
	}
	for(int i = 1; i < n; i++){
		if(a[i].s < a[i-1].s){
			printf("No\n");
			return;
		} 
	}
	
	for(int i = 0; i < n; i++){
		if(a[i].s < i){
			printf("No\n");
			return;
		} 
	}
	for(int i = 0; i < n; i++){
		c[i] = (ll)3e18;
		lw[i] = a[i].f;
	}
	k[0] = a[0].s;
	for(int i = 1; i < n; i++){
		k[i] = max(k[i-1], a[i].s);
	}
	for(int i = 0; i < n; i++){
		if(k[i] > i){
			lw[i] = max(lw[i], a[i+1].f);
		}
	}
	for(int i = 0; i < n; i++){
		if(i>0) lw[i] = max(d[i-1]+1, lw[i]);
		if(lw[i] <= c[i]){
			d[i] = lw[i];
		}else{
			printf("No\n");
			return;
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(i == n-1){
			dp[i] = n-1;
		}else if(d[i] >= a[i+1].f){
			dp[i] = dp[i+1];
		}else dp[i] = i;
	}
	for(int i = 0; i < n; i++){
		if(dp[i] != a[i].s){
			printf("No\n");
			return;
		}
	}
	cout << "Yes\n";
	for(int i = 0; i < n; i++){
		printf("%lld ", d[i]);
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