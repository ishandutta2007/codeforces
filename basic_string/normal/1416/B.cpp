#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3,M=3e4+3;
int a[N],x[M],y[M],z[M];
int main(){
	int T,n,i,j,l,t;
	long long w;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),w=0,t=0;
		for(i=1;i<=n;++i)scanf("%d",a+i),w+=a[i];
		if(w%n){puts("-1");continue;}
		l=w/n;
		for(i=2;i<=n;++i){
			if(j=a[i]%i)x[++t]=1,y[t]=i,z[t]=i-j,a[i]+=i-j;
			x[++t]=i,y[t]=1,z[t]=a[i]/i;
		}
		for(i=2;i<=n;++i)x[++t]=1,y[t]=i,z[t]=l;
		printf("%d\n",t);
		for(i=1;i<=t;++i)printf("%d %d %d\n",x[i],y[i],z[i]);
	}
	return 0;
}