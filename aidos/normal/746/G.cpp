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
int a[200200];
int n, t, k;
int dp[200200];
int d[200200];
void solve(){

	scanf("%d%d%d", &n, &t, &k);
	for(int i = 1; i <= t; i++){
		scanf("%d", &a[i]);
	}
	int l = 0;
	a[0] = 1;
	for(int i = 1; i <= t; i++){
		if(a[i] < a[i-1]) {
			l += a[i-1] - a[i];
			dp[i] = a[i-1] - a[i];
		}
		dp[i] += dp[i-1];	
	}
	l += a[t];
	int r = 0;
	for(int i = 1; i < t; i++){
		r += a[i]-1;
		d[i] = d[i-1] + a[i] - 1;
	}
	r += a[t];
	if(l > k){
		printf("-1");
		return;
	}
	if(r < k){
		printf("-1");
		return;
	}
	int ind = n;
	int cur_lev = 0;
	a[0] = 1;
	vector<pii> ans;
	for(int i = t; i > 0; i--){
		k -= a[i] - cur_lev;
		vector<int> d1, d2;
		for(int j = 0; j < a[i]; j++){
			d1.pb(ind);
			ind--;
		}
		int cur_ind = ind;
		for(int j = 0; j < a[i-1]; j++){
			d2.pb(cur_ind);
			cur_ind--;
		}
		int x = 1;
		while(x <= min(d1.size(), d2.size())){
			int l = dp[i-1] + d2.size() - x;
			int r = d[i-1] + d2.size() - x;
			if(l <= k && k <= r){
				break;
			}else x++;
		}
		cur_lev = x;	
		for(int ii = 0; ii < d1.size(); ii++){
			int j = ii % x;
			ans.pb(mp(d2[j], d1[ii]));
		}
	}
	k-=cur_lev;
	cout<<ans.size() + 1 << endl;

	for(int i = 0; i < ans.size(); i++){
		printf("%d %d\n", ans[i].f, ans[i].s);
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