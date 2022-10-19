#include<bits/stdc++.h>
using namespace std;
int T,n,k1,k2,mx1,mx2,pp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k1,&k2),mx1=mx2=0;
		for(int i=1;i<=k1;i++)scanf("%d",&pp),mx1=max(mx1,pp);
		for(int i=1;i<=k2;i++)scanf("%d",&pp),mx2=max(mx2,pp);
		puts(mx1>mx2?"YES":"NO");
	}
	return 0;
}