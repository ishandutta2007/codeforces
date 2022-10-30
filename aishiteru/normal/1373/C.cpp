#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
char s[N];
int T,n;
long long ans;
il int Min(ct p,ct q){return p<q?p:q;}
int main(){ 
	scanf("%d",&T);it i,sum=0;
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),ans=sum=0;
		for(i=1;i<=n;++i) sum+=(s[i]=='-'?-1:1),ans+=(sum<0?sum=0,i:0);
		printf("%lld\n",ans+n);
	}
	return 0;
}