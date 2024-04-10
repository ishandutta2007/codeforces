#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
const int N=3e5+3;
int q[N];
ll x[N],y[N];
int main(){
	ll p,sk=0,sb=0,xx,yy;
	int m,i,k,t=1;
	scanf("%d%d",&i,&m),p=i;
	while(m--){
		scanf("%d%d",&i,&k);
		if(i==1)sk=sb=0,x[t=1]=y[1]=0,p+=k;
		else if(i==2){
			xx=p,yy=-p*sk-sb,p+=k;
			while(t>1&&(y[t]-y[t-1])*(xx-x[t])>=(yy-y[t])*(x[t]-x[t-1]))--t;
			x[++t]=xx,y[t]=yy;
		}else scanf("%d",&i),sk+=i,sb+=k;
		while(t>1&&sk*x[t-1]+y[t-1]<=sk*x[t]+y[t])--t;
		printf("%lld %lld\n",(long long)(x[t]+1),(long long)(sk*x[t]+y[t]+sb));
	}
	return 0;
}