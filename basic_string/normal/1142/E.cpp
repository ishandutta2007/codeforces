#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int he[N],to[N],ne[N],l[N],bl[N],st[N],tp,id,d[N],q[N],a[N];
basic_string<int>g[N],scc[N];
void tar(int x){
	int i=he[x],j,p=++id;
	for(l[st[++tp]=x]=p;i;i=ne[i])if(!l[j=to[i]])tar(j),l[x]=min(l[x],l[j]);else if(!bl[j])l[x]=min(l[x],l[j]);
	if(l[x]==p)for(;bl[st[tp]]=x,scc[x]+=st[tp],st[tp--]!=x;);
}
int main(){
	int n,m,i,j,k,h=1,t=0;
	cin>>n>>m;
	while(m--)cin>>i>>j,ne[++t]=he[i],to[t]=j,he[i]=t;
	for(i=1;i<=n;++i)if(!l[i])tar(i);
	for(i=1;i<=n;++i)for(j=he[i];j;j=ne[j])if(bl[i]!=bl[k=to[j]])g[bl[i]]+=bl[k],++d[bl[k]];
	for(i=1;i<=n;++i)if(bl[i]==i)a[i]=scc[i].size();
	for(i=1,t=0;i<=n;++i)if(bl[i]==i&&!d[i])q[++t]=scc[i][--a[i]];
	while(h<t){
		if(cout<<"? "<<q[h]<<' '<<q[t]<<endl,cin>>k,!k)swap(q[h],q[t]);
		if(a[bl[j=q[t--]]])q[++t]=scc[bl[j]][--a[bl[j]]];
		else for(int o:g[bl[j]])if(!(--d[o]))q[++t]=scc[o][--a[o]];
	}
	cout<<"! "<<q[h]<<endl;
	return 0;
}