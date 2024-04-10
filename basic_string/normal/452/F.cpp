#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
#define ll unsigned long long
int a[N],n;
ll p[N],t1[N],t2[N];
void add(ll*t,int x,ll y){for(;x<=n;x+=x&-x)t[x]+=y;}
ll sum(ll*t,int x){ll y=0;for(;x;x-=x&-x)y+=t[x];return y;}
int main(){
	int T,i,j,k,x,y;
	ll u,v;
	scanf("%d",&n);
	for(i=p[0]=1;i<=n;++i)p[i]=p[i-1]*3;
	for(i=1;i<=n;++i)scanf("%d",a+i);
	j=a[1],add(t1,j,p[j]),add(t2,j,p[n-j+1]);
	for(i=2;i<n;++i){
		j=a[i],k=min(j-1,n-j);
		u=sum(t1,j+k)-sum(t1,j),v=sum(t2,j-1)-sum(t2,j-k-1);
		x=j+1,y=n-j+2;
		if(x>y?(u!=v*p[x-y]):(u*p[y-x]!=v))return puts("Yes"),0;
		add(t1,j,p[j]),add(t2,j,p[n-j+1]);
	}	
	puts("No");
	return 0;
}