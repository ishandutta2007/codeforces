#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int n,m,Z[1000011],S,l,r,p[1000011],ans;
char s[10000011];
int pov(int x){
	if(!x)return 1;
	int t=pov(x>>1);
	return (t*t%MOD)*(x&1?26:1)%MOD;
}
signed main(){
	scanf("%lld%lld%s",&n,&m,s),S=strlen(s),p[m+1]=n;
	for(int i=1;i<=m;i++)scanf("%lld",&p[i]);
	for(int i=1;i<S;i++){
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(Z[i]+i<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(Z[i]+i>r)r=Z[i]+i,l=i;
	}
//	for(int i=0;i<S;i++)printf("%lld ",Z[i]);puts("");
	for(int i=2;i<=m;i++){
		if(p[i]-p[i-1]>=S)continue;
		if(Z[p[i]-p[i-1]]<S-(p[i]-p[i-1])){puts("0");return 0;}
	}
	if(m)ans=p[1]+n-p[m]-S;
	else ans=n;
	for(int i=2;i<=m;i++)ans+=max(0ll,p[i]-p[i-1]-S);
	printf("%lld\n",pov(ans));
	return 0;
}