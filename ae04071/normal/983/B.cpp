#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

int val[5001][5001],cache[5201][5201];
int arr[5001],n;

int DP(int l,int r) {
	if(l>r) return 0;
	int &ret=cache[l][r];
	if(ret!=-1) return ret;

	ret = val[r-l+1][l];
	ret = max(ret,DP(l+1,r));
	ret = max(ret,DP(l,r-1));
	return ret;
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",arr+i);
		val[1][i]=arr[i];
	}
	for(int i=2;i<=n;i++) {
		for(int j=1;j+i-1<=n;j++) {
			val[i][j] = val[i-1][j] ^ val[i-1][j+1];
		}
	}

	memset(cache,-1,sizeof(cache));

	int q;
	scanf("%d",&q);
	while(q--) {
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",DP(l,r));
	}

	
	return 0;
}