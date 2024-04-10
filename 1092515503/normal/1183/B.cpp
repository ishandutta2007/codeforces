#include<bits/stdc++.h>
using namespace std;
int q,n,k,mx,mn,t;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k),mx=0,mn=0x3f3f3f3f;
		for(int i=1;i<=n;i++)scanf("%d",&t),mx=max(mx,t),mn=min(mn,t);
		if(mx-mn>k*2)puts("-1");
		else printf("%d\n",mn+k);
	}
	return 0;
}