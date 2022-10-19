#include<bits/stdc++.h>
using namespace std;
int s[20000005],d[20000005],qq[20000005],tot=0;
void print(){
	s[1]=1,qq[1]=1;
	for(int i=2;i<=20000000;++i){
		if(!s[i])d[++tot]=i,qq[i]=2;
		for(int j=1;j<=tot&&i*d[j]<=20000000;++j){
			s[i*d[j]]=1;
			if(i%d[j]==0){
				qq[i*d[j]]=qq[i];
				break;
			}
			qq[i*d[j]]=qq[i]*2;
		}
	}
}
int main(){
	print();
	int T;
	cin>>T;
	while(T--){
		int c,d,x;
		scanf("%d%d%d",&c,&d,&x);
		long long ans=0;
		for(int i=1;i*i<=x;++i)if(x%i==0){
			if((1ll*d*i+x)%(1ll*c*i)==0)ans+=qq[(1ll*d*i+x)/(1ll*c*i)];
			if(i*i==x)continue;
			int j=x/i;
			if((1ll*d*j+x)%(1ll*c*j)==0)ans+=qq[(1ll*d*j+x)/(1ll*c*j)];
		}
		printf("%lld\n",ans);
	}
    return 0;
}