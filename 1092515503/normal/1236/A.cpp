#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,ans,t1;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		ans=0;
		t1=c/2;
		t1=min(t1,b);
		ans+=t1*3;
		b-=t1;
		t1=b/2;
		t1=min(t1,a);
		ans+=t1*3;
		printf("%d\n",ans);
	}
	return 0;
}