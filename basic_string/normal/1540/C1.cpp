#include<bits/stdc++.h>
using namespace std;
const int N=109,M=10009,P=1e9+7;
int s[N],c[N],b[N],f[M],g[M],n;
map<int,int>mp;
int wk(int x){
	int i,j,k;
	for(memset(f,0,s[n]*4+4),i=f[0]=1;i<=n;++i){
		for(g[0]=f[0],j=1;j<=s[i];++j)if(g[j]=g[j-1]+f[j],g[j]>=P)g[j]-=P;
		for(j=0,k=x*i+b[i];j<=s[i];++j)if(j<k)f[j]=0;else if(f[j]=g[j]-(j-c[i]<1?0:g[j-c[i]-1]),f[j]<0)f[j]+=P;
	}
	for(i=j=0;i<=s[n];++i)j=(j+f[i])%P;
	return j;
}
int main(){
	int q,i,mn=P,mx=P,ms;
	for(i=1,scanf("%d",&n);i<=n;++i)scanf("%d",c+i);
	for(i=2;i<=n;++i)scanf("%d",b+i),b[i]+=b[i-1];
	for(i=2;i<=n;++i)b[i]+=b[i-1];
	for(i=1;i<=n;++i)mn=min(mn,-b[i]/i),s[i]=s[i-1]+c[i],mx=min(mx,(s[i]-b[i])/i);
	for(ms=wk(mn-=2),mx+=2,scanf("%d",&q);q--;){
		scanf("%d",&i);
		if(i<mn)printf("%d\n",ms);
		else if(i>mx)puts("0");
		else if(mp.count(i))printf("%d\n",mp[i]);
		else printf("%d\n",mp[i]=wk(i));
	}
	return 0;
}