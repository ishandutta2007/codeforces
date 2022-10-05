#include<bits/stdc++.h>
using namespace std;
const int N=2009;
int x[N],y[N],a[N],f[N];
pair<double,int>p[N];
vector<pair<int,int>>ans;
void wk(int x,int y){swap(a[x],a[y]),ans.push_back({x,y});}
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main(){
	int n,i,j=0,k,l,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)if(scanf("%d%d%d",x+i,y+i,a+i),a[i]!=i&&(!j||x[i]<x[j]))j=i;
	for(i=1;i<=n;++i)if(!f[i])for(k=i;f[k]=i,k=a[k],k!=i;);
	for(i=1;i<=n;++i)if(a[i]!=i&&i!=j)p[++t]={atan2(y[i]-y[j],x[i]-x[j]),i};
	for(i=1,sort(p+1,p+t+1);i<t;++i)if(k=p[i].second,l=p[i+1].second,gf(k)!=gf(l))wk(k,l),f[gf(k)]=gf(l);
	for(;j!=a[j];wk(j,a[j]));
	cout<<ans.size()<<'\n';
	for(auto o:ans)cout<<o.first<<' '<<o.second<<'\n';
	return 0;
}