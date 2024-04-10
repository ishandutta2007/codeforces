#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n,m,a,b,head[N],sz[N];
vector<int>g[N];
int tot,cnt,totw,dfn[N],low[N],inq[N];
bool iscut[N];
struct nd{
    int ne,to;
}e[N<<1];

void in(int x,int y){
    e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;
}

void tj(int x,int f=-1){
    static int q[N];
    dfn[x]=low[x]=++totw;
    int c=0;
    for(int i=head[x];i;i=e[i].ne)
    if(e[i].to!=f){
        int y=e[i].to;
        if(!dfn[y]){
            q[++q[0]]=i;
            tj(y,x);c++;
            if(low[y]>=dfn[x]){
                int t;++tot;
                iscut[x]=1;
                do{
                    t=q[q[0]--];
                    if(inq[e[t].to]!=tot)inq[e[t].to]=tot,g[tot].push_back(e[t].to);
                    if(inq[e[t^1].to]!=tot)inq[e[t^1].to]=tot,g[tot].push_back(e[t^1].to);
                }while(t!=i);
            }
            low[x]=min(low[x],low[y]);
        }
        else low[x]=min(low[x],dfn[y]);
    }
    if(f==-1&&c<2)iscut[x]=0;
}

void dfs(int x,int f=-1){
	sz[x]=x<=n;
	for(int i=head[x];i;i=e[i].ne)
	if(e[i].to!=f){
		int y=e[i].to;
		dfs(y,x);
		sz[x]+=sz[y];
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(int i=1;i<=n;++i)head[i]=dfn[i]=low[i]=inq[i]=iscut[i]=0;
		for(int i=1;i<=tot;++i)g[i].clear();
		tot=totw=0;
		cnt=1;
		for(int i=1,x,y;i<=m;++i){
			scanf("%d%d",&x,&y);
			in(x,y);
			in(y,x);
		}
		tj(1);
		if(!iscut[a]||!iscut[b]){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n+tot;++i)head[i]=0;
		cnt=1;
		for(int i=1;i<=tot;++i){
			for(int j=0;j<g[i].size();++j){
				in(g[i][j],i+n);
				in(i+n,g[i][j]);
			}
		}
		dfs(a);
		ll ans=sz[b]-1;
		dfs(b);
		ans=ans*(sz[a]-1);
		cout<<ans<<endl;
	}
}