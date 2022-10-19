#include<bits/stdc++.h>
using namespace std;
#define int long long
const int LG=61;
int n,opt,t1,t2,t3,pov[LG];
map<int,int>m;
int sum(int u,int v){
	if(u>v)swap(u,v);
	int U=upper_bound(pov,pov+LG,u)-pov-1,V=upper_bound(pov,pov+LG,v)-pov-1,s=0;
//	printf("%lld %lld\n",U,V);
	while(V>U){
		if(m.find(v)!=m.end())/*printf("%lld\n",v),*/s+=m[v];
		V--,v>>=1;
	}
	while(v!=u){
		if(m.find(u)!=m.end())s+=m[u];
		if(m.find(v)!=m.end())s+=m[v];
//		printf("%lld %lld\n",u,v);
		u>>=1,v>>=1;
	}
	return s;
}
void add(int u,int v,int w){
	if(u>v)swap(u,v);
	int U=upper_bound(pov,pov+LG,u)-pov-1,V=upper_bound(pov,pov+LG,v)-pov-1;
//	printf("%lld %lld\n",U,V);
	while(V>U)/*printf("%lld\n",v),*/m[v]+=w,V--,v>>=1;
	while(v!=u)/*printf("%lld %lld\n",u,v),*/m[u]+=w,m[v]+=w,u>>=1,v>>=1;
}
signed main(){
	scanf("%lld",&n),pov[0]=1;
	for(int i=1;i<LG;i++)pov[i]=pov[i-1]<<1/*,printf("%lld\n",pov[i])*/;
	for(int i=1;i<=n;i++){
		scanf("%lld",&opt);
		if(opt==1)scanf("%lld%lld%lld",&t1,&t2,&t3),add(t1,t2,t3);
		else scanf("%lld%lld",&t1,&t2),printf("%lld\n",sum(t1,t2));
	}
	return 0;
}