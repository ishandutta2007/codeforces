#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional> 
#include <stack>
#include <cstring>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int inf=1e9;

int cache[5002][5001][3],n,arr[5001];
int DP(int idx,int k,int s) {
	int &ret=cache[idx][k][s];
	if(ret!=-1) return ret;

	if(k==0 && (idx==n+1 || s!=2)) return ret=0;
	else if(idx==n+1) return ret=inf;

	ret=inf;
	if(s==0) { // down;
		if(idx==1) ret=min(ret,DP(idx+1,k-1,2));
		else {
			int val=arr[idx-2]-1;
			ret = min(ret, DP(idx+1,k-1,2)+max(0,val-arr[idx]+1));
		}
		ret = min(ret,DP(idx+1,k,1));
	} else if(s==1) {
		ret = min(ret, DP(idx+1,k-1,2)+max(0,arr[idx-1]-arr[idx]+1));
		ret = min(ret,DP(idx+1,k,1));
	} else {
		if(arr[idx] < arr[idx-1]) ret = min(ret,DP(idx+1,k,1));
		ret = min(ret, DP(idx+1,k,0)+max(0,arr[idx]-arr[idx-1]+1));
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	memset(cache,-1,sizeof(cache));
	for(int i=1;i<=(n+1)/2;i++) {
		printf("%d ",DP(1,i,0));
	}
	return 0;
}