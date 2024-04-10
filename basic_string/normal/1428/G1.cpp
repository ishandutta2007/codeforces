#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=N+3;
#define ll long long
int q[M];
ll a[7],f[M],g[M];
int main(){
	int m,i,j,k,l,w,u,h,t;
	ll v,o,p;
	scanf("%d",&m),m=m*3-3;
	for(i=0;i<6;++i)scanf("%lld",a+i);
	for(i=0;i<N;++i)for(j=0,k=i;j<6;++j,k/=10)if((l=k%10)%3==0)f[i]+=l/3*a[j];
	for(i=0,u=3;i<6;++i,u*=10){
		v=a[i],w=u;
		for(j=0;j<w;++j){
			q[h=t=0]=j,g[0]=f[j],l=max(j-m*1ll*w,-1ll<<29),o=v;
			for(k=j+w;k<N;k+=w,l+=w,o+=v){
				if(q[h]==l)++h;
				p=f[k]-o;
				if(h<=t)f[k]=max(f[k],g[h]+o);
				while(h<=t&&g[t]<p)--t;
				q[++t]=k,g[t]=p;
			}
		}
	}
	scanf("%d",&m);
	while(m--)scanf("%d",&i),printf("%lld\n",f[i]);
	return 0;
}