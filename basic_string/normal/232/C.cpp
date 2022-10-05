#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll f[89]={1,2},p[89];
int s[89][4][4];
int get(ll a,int n){
	if(a==1)return 0;
	if(a==f[n])return 1;
	if(!p[n])p[n]=a;
	if(a==p[n])return 2;
	return 3;
}
int wk(ll a,ll b,int n){
	if(a==b)return 0;
	if(a>b)swap(a,b);
	int u=get(a,n),v=get(b,n);
	if(s[n][u][v])return s[n][u][v];
	ll d=f[n-1];
	return s[n][u][v]=
	a>d?wk(a-d,b-d,n-2)
	:(b>d?min(wk(a,d,n-1),wk(a,1,n-1))+1+wk(b-d,1,n-2)
	:min(wk(a,b,n-1),min(wk(a,1,n-1)+wk(b,d,n-1),wk(a,d,n-1)+wk(b,1,n-1))+2));
}
int main(){
	int T,n,i;
	ll a,b;
	for(scanf("%d%d",&T,&n),n=min(n,80),i=2;i<=n;++i)f[i]=f[i-1]+f[i-2];
	while(T--)memset(s,0,sizeof s),memset(p,0,sizeof p),scanf("%lld%lld",&a,&b),printf("%d\n",wk(a,b,n));
	return 0;
}