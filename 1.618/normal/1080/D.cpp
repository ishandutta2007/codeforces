#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k;
ll maxk[35];
int main(){
	maxk[1] = 1;
	int lim;//32
	for(lim=2;maxk[lim - 1] <= (ll)1e18;lim++)
	  maxk[lim] = (maxk[lim - 1] << 2) + 1;
	maxk[lim] = (maxk[lim - 1] << 2) + 1;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		if(n > lim){
			printf("YES %I64d\n",n - 1);
		}else if(k <= maxk[n - 1] + 1){
			printf("YES %I64d\n",n - 1);
		}else if(k <= maxk[n] - (1ll << n) + 1){
			printf("YES 1\n");
		}else if(k <= maxk[n]){
			if(n == 2 && k == 3) printf("NO\n");
			else printf("YES 0\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}