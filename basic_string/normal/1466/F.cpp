#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int qp(int a,int b,int r=1){
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
const int N=2e6+3;
basic_string<int>g[N],ans;
bool b[N],v[N];
map<pair<int,int>,int>id;
int ct,f[N],u[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
struct P{
	int x,y,d;
	bool operator<(P a)const{return d<a.d;}
}p[N];
int st[N],tp;
void dfs(int x){
	v[x]=1,st[++tp]=x;
	for(int j:g[x]){
		if(!b[j])p[++ct]={x,j,id[{x,j}]};
		if(!v[j])dfs(j);
	}
}
int main(){
	int n,m,i,j,k,l,s=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&k);
		if(k==1)scanf("%d",&j),u[j]=i;
		else scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j,id[{j,k}]=id[{k,j}]=i;
	}
	/*for(i=1;i<=m;++i)if(b[i])q.push(i);
	while(!q.empty()){
		i=q.front(),q.pop();
		for(int j:g[i])if(!b[j])b[j]=1,q.push(j),ans+=id[{i,j}];
	}*/
//	for(i=1;i<=m;++i)if(b[i])++s,v[i]=1;
	for(i=1;i<=m;++i)f[i]=i;
	u[0]=1e9;
	for(i=1;i<=m;++i)if(!v[i]&&u[i]){
		ct=0,tp=0,dfs(i),s+=tp,l=0;
		for(j=1;j<=tp;++j){
			b[st[j]]=1;
			if(u[st[j]]&&u[st[j]]<u[l])l=st[j];
		}
		ans+=u[l];
		for(j=1;j<=tp;++j)if(u[st[j]]&&st[j]!=l)p[++ct]={st[j],l,u[st[j]]};
		sort(p+1,p+ct+1);
		for(j=1;j<=ct;++j){
			if(gf(p[j].x)!=gf(p[j].y))f[gf(p[j].x)]=gf(p[j].y),ans+=p[j].d;
		}
	}
	for(i=1;i<=m;++i)if(!v[i]){
		ct=0,tp=0,dfs(i),s+=tp-1;
		for(j=1;j<=tp;++j)b[st[j]]=1;
		sort(p+1,p+ct+1);
		for(j=1;j<=ct;++j){
			if(gf(p[j].x)!=gf(p[j].y))f[gf(p[j].x)]=gf(p[j].y),ans+=p[j].d;
		}
	}
	cout<<qp(2,s)<<' '<<ans.size()<<'\n';
	sort(ans.begin(),ans.end());
	for(int i:ans)cout<<i<<' '; 
	return 0;
}