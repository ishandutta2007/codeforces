#include<bits/stdc++.h>
using namespace std;
int t,b,f,p,h,c,ans;
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
		if(h>c){
			ans=min(p,b/2)*h;
			if(b/2>p) ans+=min((b-p*2)/2,f)*c;
		}
		else {
			ans=min(f,b/2)*c;
			if(b/2>f) ans+=min((b-f*2)/2,p)*h;
		}
		printf("%d\n",ans);
	}
	return 0;
}