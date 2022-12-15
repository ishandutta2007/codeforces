#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int inf=1e9;

int n,k,arr[200001];
lli cnt[200001];
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	
	lli c=0,val=1;
	map<lli,lli> tr[3];
	for(int i=0;i<n;i++) {
		lli val = 1ll*k*k;
		for(int j=2;j>=0;j--,val/=k) if(arr[i] % val == 0) {
			lli t=arr[i] / val;
			if(j==0) tr[0][t] += 1;
			else tr[j][t] += tr[j-1][t];
		}
	}
	

	lli ans=0;
	for(auto &it:tr[2]) ans += it.second;
	printf("%lld\n",ans);
	
	return 0;
}