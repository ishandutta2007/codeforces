#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
int id,l[N],r[N],p[N],now,ans;
basic_string<int>g[N],h[N];
set<int>s;
set<int>::iterator it,i2;
void get(int x){
	l[x]=++id,p[id]=x;
	for(int i:h[x])get(i);
	r[x]=id;
}
void dfs(int x){
	int d=0,a=0;
	if(it=i2=s.lower_bound(l[x]),it!=s.begin()&&r[p[*--it]]>=r[x])a=l[x],d=*it,s.erase(d),s.insert(a);
	else if(i2==s.end()||*i2>r[x])a=l[x],s.insert(a),++now;
	ans=max(ans,now);
	for(int i:g[x])dfs(i);
	if(d)s.insert(d),++now;
	if(a)s.erase(a),--now;
}
int main(){
	int T,n,i,j;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n),id=0;
		for(i=1;i<=n;++i)g[i]=h[i]={}; 
		for(i=2;i<=n;++i)scanf("%d",&j),g[j]+=i;
		for(i=2;i<=n;++i)scanf("%d",&j),h[j]+=i;
		get(1),now=ans=0,dfs(1),printf("%d\n",ans); 
	}
	return 0;
}