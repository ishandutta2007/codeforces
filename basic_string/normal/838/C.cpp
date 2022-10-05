#include<bits/stdc++.h>
using namespace std;
const int N=250009;
int n,p,k,jc[N],ijc[N],f[23][N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;
	return r;
}
int get(int t,int s){
	if(~f[t][s])return f[t][s];
	if(!s){
		int w=jc[n],i=1;
		for(;i<=t;++i)w=w*1ll*(k-i+1)%p;
		return f[t][s]=w;
	}
	int i,w=0,u=s-(s&-s);
	for(i=u;;i=i-1&u)if(w=(w+get(t+1,i)*1ll*ijc[s-i])%p,!i)break;
	return f[t][s]=w;
}
int main(){
	int i;
	if(scanf("%d%d%d",&n,&k,&p),n&1)printf("%d",qp(k,n)),exit(0);
	for(jc[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%p;
	for(ijc[n]=qp(jc[i=n],p-2);i;--i)ijc[i-1]=ijc[i]*1ll*i%p;
	memset(f,-1,sizeof f),printf("%d",(qp(k,n)-get(0,n)+p)%p);
	return 0;
}