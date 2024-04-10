#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n,m,Q,cc;
int d[N],f[N],head[N],a[N];

struct nd{
	int ne,to;
}e[N<<1];

void in(int x,int y){
	static int cnt;
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;
}

void dfs_init(int x){
    for(int i=head[x];i;i=e[i].ne)
    if(e[i].to!=f[x]){
        int y=e[i].to;
        d[y]=d[x]+1;
        f[y]=x;
        dfs_init(y);
    }
}

int fa[N];
vector<int> l,r,ans[N];

int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}

void dfs(int x,int y){
	while(1){
		if(x==y){
			l.push_back(x);
			return;
		}
		else if(d[x]>=d[y]){
			l.push_back(x);
			x=f[x];
		}
		else if(d[x]<d[y]){
			r.push_back(y);
			y=f[y];
		}
	}
}

void dfs2(int x){
	int c=0;
    for(int i=head[x];i;i=e[i].ne)
    if(e[i].to!=f[x]){
        int y=e[i].to;
        dfs2(y);
        a[x]^=a[y];
        if(a[y])++c;
    }
    cc-=c/2;
    if(c%2==0&&a[x])++cc;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		if(gf(x)==gf(y))continue;
		fa[gf(x)]=gf(y);
		in(x,y);
		in(y,x);
	}
	dfs_init(1);
	cin>>Q;
	for(int i=1,x,y;i<=Q;++i){
		scanf("%d%d",&x,&y);
		a[x]^=1;
		a[y]^=1;
		l.clear();
		r.clear();
		dfs(x,y);
		reverse(r.begin(),r.end());
		for(int j=0;j<l.size();++j)ans[i].push_back(l[j]);
		for(int j=0;j<r.size();++j)ans[i].push_back(r[j]);
	}
	dfs2(1);
	if(cc>0){
		printf("NO\n%d\n",cc);
	}
	else{
		printf("YES\n");
		for(int i=1;i<=Q;++i){
			printf("%d\n",ans[i].size());
			for(int j=0;j<ans[i].size();++j)printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
}