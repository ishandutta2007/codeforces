#include<bits/stdc++.h>
using namespace std;
const int N=1009;
bitset<1000009>b[N];
int u[N],v[N],n,m,p[N],q[N],d[N];
bool dp(int*a,int s,int*c){
	int i,t=0,o=0;
	b[0].reset(),b[0][0]=1;
	for(i=1;i<=n;++i)b[i]=b[i-1]|(b[i-1]<<a[i]);
	if(!b[n][s])return 1;
	for(i=n;i;--i)if(s>=a[i]&&b[i-1][s-a[i]])c[++o]=a[i],s-=a[i];else d[++t]=a[i];
	for(i=1;i<=t;++i)c[o+i]=-d[i];
	return 0;
}
int main(){
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),x=y=0;
		for(i=1;i<=n;++i)scanf("%d",u+i),x+=u[i];
		scanf("%d",&m);
		for(i=1;i<=m;++i)scanf("%d",v+i),y+=v[i];
		if(n!=m||(x&1)||(y&1)){puts("No");continue;}
		x/=2,y/=2,sort(u+1,u+n+1),sort(v+1,v+m+1);
		if(dp(u,x,p)||dp(v,y,q)){puts("No");continue;}
		puts("Yes"),reverse(q+1,q+m+1),x=y=0;
		for(i=1;i<=n*2;++i){
			if(i&1)x+=p[i/2+1];else y+=q[i/2];
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}