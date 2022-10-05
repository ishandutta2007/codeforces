#include<bits/stdc++.h>
using namespace std;
int s[500009];
int main(){
	long long ans=0;
	int n,i,j,t=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&j);
		while(t>1&&s[t]<=s[t-1]&&s[t]<=j)ans+=min(s[--t],j);
		s[++t]=j;
	}
	for(i=1;i<=t;++i)ans+=s[i];
	for(i=1;i<=t;++i)if(s[i]>=s[i-1]&&s[i]>=s[i+1])return printf("%lld",ans-s[i]-max(s[i-1],s[i+1])),0;
	return 0;
}