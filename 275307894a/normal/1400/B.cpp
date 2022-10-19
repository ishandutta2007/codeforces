#include<bits/stdc++.h>
using namespace std;
long long  n,m,k,x,y,z,t,sx,sy,ans,tot,now,pus,now1,now2;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&x,&y,&sx,&sy);
		ans=0;
		if(sx>sy) swap(x,y),swap(sx,sy);
		for(i=0;i<=x;i++){
			pus=i;
			if(i*sx>n) break;
			tot=i*sx;
			tot=n-tot;
			if(sy*y<=tot){
				pus+=y;
				if((x-i)*sx<=m) pus+=x-i;
				else pus+=m/sx;
			}
			else{
				pus+=tot/sy;
				now=y-tot/sy;
				if((x-i)*sx<=m){
					pus+=x-i;
					now1=m-(x-i)*sx;
					if(now1>=now*sy) pus+=now;
					else pus+=now1/sy;
				} 
				else pus+=m/sx;
			}
			ans=max(ans,pus);
		}
		printf("%d\n",ans);
	}
}