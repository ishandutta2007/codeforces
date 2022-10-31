#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x,pr=-1,pb=-1,pg=-1,mr,mb;
	long long ans=0;
	char c;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %c",&x,&c);
		if(c=='G'){
			if(pr>0) ans+=x-pr,mr=max(x-pr,mr);
			if(pb>0) ans+=x-pb,mb=max(x-pb,mb);
			if(pg>0&&(mr+mb>x-pg)){
				ans-=mr;
				ans-=mb;
				ans+=x-pg;
			}
			pr=pb=pg=x;
			mr=mb=0;
		}
		else if(c=='R'){
			if(pr>0){
				ans+=x-pr;
				mr=max(mr,x-pr);
			}
			pr=x;
		}
		else if(c=='B'){
			if(pb>0){
				ans+=x-pb;
				mb=max(mb,x-pb);
			}
			pb=x;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}