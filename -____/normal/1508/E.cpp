#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 333333;
int n,f[N],a[N],l[N],r[N],t[N],d[N];
vector<int> v[N];
LL ans;
void dfs1(int u){
	int i,x;
	l[u]=a[u],r[u]=a[u],t[u]=1;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		d[x]=d[u]+1;
		dfs1(x);
		l[u]=min(l[u],l[x]);
		r[u]=max(r[u],r[x]);
		t[u]+=t[x];
	}
}
int s1[N],s2[N];
bool chk1(int u){
	if(s1[u]>=0)
		return s1[u];
	s1[u]=0;
	if(r[u]-l[u]+1!=t[u])
		return 0;
	if(a[u]!=r[u])
		return 0;
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(!chk1(x))
			return 0;
	}
	s1[u]=1;
	return 1;
}
bool chk2(int u){
	if(s2[u]>=0)
		return s2[u];
	s2[u]=0;
	if(r[u]-l[u]+1!=t[u])
		return 0;
	if(a[u]!=l[u])
		return 0;
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(!chk2(x))
			return 0;
	}
	s2[u]=1;
	return 1;
}
bool chk3(int u){
	if(r[u]-l[u]+1!=t[u]+d[u])
		return 0;
	int i,x,o=0;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(r[x]<a[1]){
			if(!chk1(x))
				return 0;
			continue;
		}
		if(l[x]>a[1]){
			if(!chk2(x))
				return 0;
			continue;
		}
		if(o)
			return 0;
		o=x;
	}
	if(!o)
		return 1;
	if(a[o]!=a[u]+1)
		return 0;
	return chk3(o);
}
int m,b[N];
void go(int u){
	int i,x,o;
	vector<pair<int,int> > p;
	b[u]=++m;
	o=v[u].size();
	p.resize(o);
	for(i=0;i<o;i++){
		x=v[u][i];
		p[i]=make_pair(l[x],x);
	}
	sort(p.begin(),p.end());
	for(i=0;i<o;i++)
		go(p[i].second);
}
bool solve(){
	int i;
	dfs1(1);
	for(i=1;i<=n;i++)
		s1[i]=-1,s2[i]=-1;
	if(chk3(1)){
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++)
			if(a[i]<a[1])
				ans+=d[i];
		cout<<ans<<endl;
		go(1);
		for(i=1;i<=n;i++)
			cout<<b[i]<<' ';
		return 1;
	}
	return 0;
}
int main(){
	int i,j,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		f[y]=x;
	}
	if(solve()){
		return 0;
	}
	if(a[1]==1){
		cout<<"NO";
		return 0;
	}
	for(i=1;i<=n;i++)
		if(a[i]==a[1]-1)
			break;
	while(i!=1){
		if(a[i]>a[f[i]]){
			cout<<"NO";
			return 0;
		}
		for(j=0;j<v[f[i]].size();j++){
			x=v[f[i]][j];
			if(x!=i&&a[i]<a[x]&&a[x]<a[f[i]]){
				cout<<"NO";
				return 0;
			}
		}
		swap(a[i],a[f[i]]);
		ans++;
		i=f[i];
	}
	if(solve()){
		return 0;
	}
	cout<<"NO";
	return 0;
}