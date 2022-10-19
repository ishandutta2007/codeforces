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

#define inf 1000000
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 300300
#define mod 1000000007

#define time ofuherf

typedef long long ll;
using namespace std;

int pai[maxn];
int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}
int v[maxn];
int on[maxn];
ll sum[maxn];
int op[maxn];

main(){

	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	vector<ll> ans;
	ans.pb(0);
	ll cur = 0;

	for(int i=0;i<n;i++)
		scanf("%d",op+i), op[i]--;

	for(int i=0;i<n;i++){
		pai[i] = i;
		sum[i] = v[i];
	}

	for(int i=n-1;i>=0;i--){
		debug("liga %d\n",op[i]);
		on[op[i]] = 1;
		if(op[i] != n-1 && on[op[i]+1]){
			int a = find(op[i]+1);
			ll r = sum[find(op[i])];
			debug("join %d %d\n",find(op[i]),a);
			pai[find(op[i])] = a;
		
			sum[a] += r;
		}
		if(op[i] && on[op[i]-1]){
			int a = find(op[i]-1);
			ll r = sum[find(op[i])];
			debug("join %d %d\n",find(op[i]),a);
			pai[find(op[i])] = a;
			sum[a] += r;
		}
		debug("has %lld\n",sum[find(op[i])]);
		cur = max(cur,sum[find(op[i])]);
		ans.pb(cur);
	}

//	reverse(ans.begin(),ans.end());

	for(int i=ans.size()-2;i>=0;i--)
		printf("%lld\n",ans[i]);

}