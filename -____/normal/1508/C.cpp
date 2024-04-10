#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 222222;
int n,m,a[N],b[N],c[N],f[N],e[N];
vector<int> v[N];
bool chk(int x,int y){
	return (*lower_bound(v[x].begin(),v[x].end(),y))==y;
}
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
vector<int> u0,u1;
void uni(int x,int y){
	u0.push_back(x);
	u1.push_back(y);
	x=fnd(x),y=fnd(y);
	f[y]=x;
}
queue<int> q;
set<int> r;
vector<int> tmp;
void bfs(int s){
	set<int>::iterator it;
	int x,i;
	e[s]=1;
	r.erase(s);
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		for(it=r.begin();it!=r.end();it++){
			x=*it;
			if(!chk(s,x)){
				uni(s,x);
				e[x]=1;
				tmp.push_back(x);
				q.push(x);
			}
		}
		for(i=0;i<tmp.size();i++)
			r.erase(tmp[i]);
		tmp.clear();
	}
}
int g[N];
int fndg(int x){
	if(g[x]==x)
		return x;
	return g[x]=fndg(g[x]);
}
pair<int,int> p[N];
int main(){
	int i,j,k,x,y,z,w;
	LL ans,ss;
	scanf("%d%d",&n,&m);
	w=0;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y);
		v[y].push_back(x);
		a[i]=x,b[i]=y,c[i]=z;
		p[i]=make_pair(z,i);
		w^=z;
	}
	for(i=1;i<=n;i++){
		v[i].push_back(N);
		sort(v[i].begin(),v[i].end());
	}
	for(i=1;i<=n;i++)
		f[i]=i,e[i]=0,r.insert(i);
	for(i=1;i<=n;i++)
		if(!e[i])
			bfs(i);
	ss=(LL)n*(n-1)/2-m-u0.size();
	if(ss){
		sort(p+1,p+m+1);
		ans=0;
		for(i=1;i<=n;i++)
			g[i]=fnd(i);
		for(i=1;i<=m;i++){
			j=p[i].second;
			if(fndg(a[j])!=fndg(b[j]))
				g[fndg(a[j])]=fndg(b[j]),ans+=c[j];
		}
		cout<<ans;
		return 0;
	}
	ans=1e18;
	p[0]=make_pair(w,0);
	sort(p,p+m+1);
	for(k=0;k<u0.size();k++){
		a[0]=u0[k],b[0]=u1[k],c[0]=w;
		ss=0;
		for(i=1;i<=n;i++)
			g[i]=i;
		for(i=0;i<u0.size();i++)
			if(i!=k)
				g[fndg(u0[i])]=fndg(u1[i]);
		for(i=0;i<=m;i++){
			j=p[i].second;
			if(fndg(a[j])!=fndg(b[j]))
				g[fndg(a[j])]=fndg(b[j]),ss+=c[j];
		}
		ans=min(ans,ss);
	}
	cout<<ans;
	return 0;
}