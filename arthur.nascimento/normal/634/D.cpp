#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 300300

typedef long long ll;
using namespace std;

int pos[maxn];
int price[maxn];

int dp[20][maxn];

int nxt[maxn];
int lg[maxn];

int get(int a,int b){
	int sz = b-a+1;
	int t = lg[sz];
	return min(dp[t][a], dp[t][b-(1<<t)+1]);
}

main(){

	lg[1] = 0;
	for(int i=2;i<maxn;i++){
		lg[i] = lg[i-1];
		if(i == (i&-i))
			lg[i]++;
	}

	int d,n,k;
	scanf("%d%d%d",&d,&n,&k);

	vector<pii> u;
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		u.pb(pii(x,y));
	}
	sort(u.begin(), u.end());

	for(int i=0;i<k;i++){
		pos[i] = u[i].first;
		price[i] = u[i].second;
	}

	for(int i=0;i<k;i++)
		dp[0][i] = price[i];

	for(int i=1;i<20;i++)
		for(int j=0;j<k;j++)
			dp[i][j] = min(dp[i-1][j], dp[i-1][min(k-1,j+(1<<(i-1)))]);

	nxt[k-1] = -1;

	for(int i=0;i<k-1;i++){

		if(get(i+1,k-1) >= price[i]){
			nxt[i] = -1;
			continue;
		}

		int low = i+1, up = k-1;

		while(low != up){
			int mid = (low+up)/2;
			if(get(i+1,mid) < price[i])
				up = mid;
			else
				low = mid+1;
		}

		nxt[i] = low;

	}

	for(int i=0;i<k;i++)
		debug("nxt[%d] = %d\n",i,nxt[i]);

	ll ans = 0;
	int cur = 0, cap = n-pos[0];

	while(cur != k){

		debug("at x=%d cap %d\n",pos[cur],cap);

		if(cap < 0){
			printf("-1\n");
			return 0;
		}

		if(nxt[cur] == -1){
			int need = d - pos[cur] - cap;
			need = max(need,0);
			int buy = min(need,n-cap);
			ans += (ll) (buy) * price[cur];
			debug("buy %d\n",buy);
			cap = n;
		}
		else {
			int need = pos[nxt[cur]] - pos[cur];
			if(cap < need){
				int buy = min(need-cap,n-cap);
				ans += (ll) (buy) * price[cur];
				debug("!buy %d\n",need-cap);
				cap += buy;
			}
		}
		if(cur != k-1){
			cap -= pos[cur+1]-pos[cur];
			cur++;
		}
		else {
			cap -= d-pos[cur];
			cur++;
		}
	}

	if(cap < 0){
		printf("-1\n");
	}
	else
		cout << ans << endl;

}