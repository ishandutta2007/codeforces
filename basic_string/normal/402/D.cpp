#include<bits/stdc++.h>
using namespace std;
const int N=5009,M=33337;
int a[N],g[N],p[M];
bool f[M];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
unordered_map<int,bool>mp;
int get(int x){
	int i,r=0;
	for(i=1;p[i]*p[i]<=x;++i)if(x%p[i]==0){
		do x/=p[i],r+=mp[p[i]]?-1:1;while(x%p[i]==0);
	}
	if(x>1)r+=mp[x]?-1:1;
	return r;
}
int main(){
	int n,m,i,j,k,t=0,w=1,s=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	while(m--)scanf("%d",a+i),mp[a[i]]=1;
	for(g[1]=a[1],i=2;i<=n;++i)g[i]=gcd(a[i],g[i-1]);
	for(i=2;i<M;++i){
		if(!f[i])p[++t]=i;
		for(j=1;j<=t&&(k=i*p[j])<M;++j){
			f[k]=1;
			if(i%p[j]==0)break;
		}
	}
	for(i=n;i;--i){
		j=get(g[i]/w);
		if(j<0)w=g[i];
		s+=get(a[i]/w);
	}
	printf("%d",s);
	return 0;
}