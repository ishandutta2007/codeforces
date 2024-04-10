#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+3;
ll d[N],u[N],v[N],a[N];
int q[N];
#define get(i,j) (g[i]-(i)*a[j])
int main(){
	int n,m,p,i,j,k,l,h,t;
	ll *f=u,*g=v,s=0;
	scanf("%d%d%d",&n,&m,&p);
	if(p>=m)return puts("0"),0;
	for(i=2;i<=n;++i)scanf("%lld",d+i),d[i]+=d[i-1];
	for(i=1;i<=m;++i)scanf("%d%d",&j,&k),s-=(a[i]=k-d[j]),f[i]=1e18;
	sort(a+1,a+m+1);
	for(i=1;i<=p;++i){
		swap(f,g),q[h=t=1]=0;
		for(j=1;j<=m;++j){
			while(h<t&&get(q[h],j)>get(q[h+1],j))++h;
			f[j]=get(q[h],j)+a[j]*j;
			while(h<t&&(g[q[t]]-g[q[t-1]])*(j-q[t])>(g[j]-g[q[t]])*(q[t]-q[t-1]))--t;
			q[++t]=j;
		}
	}
	printf("%lld",s+f[m]);
	return 0;
}