#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
 
int n,m,head[N];
int f[N][20],fa[N],d[N];
int u[N],v[N],g[N];
int a[N],b[N];
int cnt[N],cnt1[N],cnt2[N];
ll ans;
 
struct nd{
	int ne,to;
}e[N<<2];
 
void in(int x,int y){
	static int cnt;
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;
}
 
void dfs(int x){
	for(int i=head[x];i;i=e[i].ne)
	if(e[i].to!=fa[x]){
		int y=e[i].to;
		fa[y]=f[y][0]=x;
		d[y]=d[x]+1;
		dfs(y);
	}
}
 
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=19;~i;--i)
	if(d[f[x][i]]>=d[y]){
		x=f[x][i];
	}
	if(x==y)return x;
	for(int i=19;~i;--i)
	if(f[x][i]!=f[y][i]){
		x=f[x][i];
		y=f[y][i];
	}
	return f[x][0];
}
 
int cfa(int x,int y){
	for(int i=19;~i;--i)
	if(d[f[x][i]]>d[y]){
		x=f[x][i];
	}
	return x;
}
 
ll c(int x){
	return 1ll*x*(x-1)/2;
}
 
void dfs1(int x){
	for(int i=head[x];i;i=e[i].ne)
	if(e[i].to!=fa[x]){
		int y=e[i].to;
		cnt[y]+=cnt[x];
		cnt1[y]+=cnt1[x];
		cnt2[y]+=cnt2[x];
		dfs1(y);
	}
}
 
int main(){
//	freopen("c.in","r",stdin);
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		in(x,y);
		in(y,x);
	}
	d[1]=1;
	dfs(1);
	for(int j=1;j<20;++j)
	for(int i=1;i<=n;++i)
	f[i][j]=f[f[i][j-1]][j-1];
	scanf("%d",&m);
	int t1=0,t2=0;
	static vector<int> tmp1[N];
	static vector<pair<int,int>> tmp2[N];
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		int l=lca(x,y);
		if(y==l)swap(x,y);
		if(x==y){
			cnt[x]++;
		}
		else if(x==l){
			++t1;
			a[t1]=x;
			b[t1]=y;
			int f=cfa(y,x);
			cnt1[x]++;
			cnt1[f]--;
			tmp1[x].push_back(f);
		}
		else{
			++t2;
			u[t2]=x;
			v[t2]=y;
			g[t2]=l;
			cnt2[l]++;
			int fx=cfa(x,l);
			int fy=cfa(y,l);
			cnt2[fx]--;
			cnt2[fy]--;
			if(fx<fy)swap(fx,fy);
			tmp2[l].push_back(make_pair(fx,fy));
		}
	}
	for(int i=1;i<=n;++i)ans+=c(cnt[i]);
	for(int i=1;i<=n;++i){
		sort(tmp1[i].begin(),tmp1[i].end());
		int tot=0;
		for(int j=0,r=0;j<tmp1[i].size();j=++r){
			int x=tmp1[i][j];
			while(r+1<tmp1[i].size()&&tmp1[i][r+1]==x)++r;
			int cnt=r-j+1;
			ans+=1ll*cnt*tot;
			ans+=1ll*cnt*cnt;
			tot+=cnt;
		}
	}
	for(int i=1;i<=n;++i){
		sort(tmp2[i].begin(),tmp2[i].end());
		int cnt=tmp2[i].size();
		ans+=c(cnt);
		static int t[N],t1[N];
		for(int j=0;j<tmp1[i].size();++j){
			t1[tmp1[i][j]]++;
		}
		for(int j=0;j<cnt;++j){
			ans+=tmp1[i].size()-t1[tmp2[i][j].first]-t1[tmp2[i][j].second];
			ans+=t1[tmp2[i][j].first]*2;
			ans+=t1[tmp2[i][j].second]*2;
			ans+=t[tmp2[i][j].first]*2;
			ans+=t[tmp2[i][j].second]*2;
			ans+=2;
			t[tmp2[i][j].first]++;
			t[tmp2[i][j].second]++;
		}
		for(int j=head[i];j;j=e[j].ne){
			int y=e[j].to;
			ans-=c(t[y]);
			t[y]=0;
			t1[y]=0;
		}
		for(int j=0,r=0;j<cnt;j=++r){
			while(r+1<cnt&&tmp2[i][r+1]==tmp2[i][j])++r;
			ans+=c(r-j+1);
		}
	}
	dfs1(1);
	for(int i=1;i<=t1;++i){
		ans+=cnt[b[i]]-cnt[fa[a[i]]];
		ans+=cnt1[b[i]]-cnt1[a[i]];
		ans+=cnt2[b[i]]-cnt2[a[i]];
	}
	for(int i=1;i<=t2;++i){
		ans+=cnt[u[i]]+cnt[v[i]]-cnt[fa[g[i]]]-cnt[g[i]];
		ans+=cnt1[u[i]]+cnt1[v[i]]-2*cnt1[g[i]];
		ans+=cnt2[u[i]]+cnt2[v[i]]-2*cnt2[g[i]];
	}
	printf("%lld\n",ans);
}