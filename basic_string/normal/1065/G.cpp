#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=4e18;
ll f[209];
string s[19],ss[999],ans;
int get(string s){
	int i=0,j=0;
	for(;~(i=s.find(ans,i));++i,++j);
	return j;
}
int main(){
	int i,n,m;
	ll o,a0,a1,a01,a10,a11,b0,b1,b01,b10,b11,x;
	scanf("%d%lld%d",&n,&o,&m),f[1]=1,s[0]="0",s[1]="1";
	for(i=2;i<=n;++i)f[i]=min(inf,f[i-1]+f[i-2]);
	for(i=2;i<16;++i)s[i]=s[i-2]+s[i-1];
	if(n<16){
		for(i=0;i<s[n].size();++i)ss[i]=s[n].substr(i);
		sort(ss,ss+s[n].size()),cout<<ss[o-1].substr(0,m);
		return 0;
	}
	a0=f[n-15],a1=f[n-14],a01=a0,a10=a0+1-(n&1),a11=(a1==inf)?inf:(a0+a1-1-a01-a10);
	for(i=1;i<=m;++i){
		ans+='0',b0=get(s[14]),b1=get(s[16]),b01=get(s[14]+s[15])-b0-b1,b10=get(s[15]+s[14])-b0-b1,b11=get(s[15]+s[15])-b1*2;
		if((double)b0*a0+(double)b1*a1+(double)b01*a01+(double)b10*a10+(double)b11*a11>inf)x=inf;
		else x=b0*a0+b1*a1+b01*a01+b10*a10+b11*a11;
		if(x<o)o-=x,ans.back()='1';
	}
	cout<<ans;
	return 0;
}