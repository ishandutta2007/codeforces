#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e5+5;

int T;
int n,cnt,head[N],sz[N];
ll ans1,ans2;
struct nd{
	int ne,to,w;
}e[N<<1];

void in(int x,int y,int w){
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;e[cnt].w=w;
}

bool dfs1(int x,int f=-1){
	int c=0;
	sz[x]=1;
	for(int i=head[x];i;i=e[i].ne)
	if(e[i].to!=f){
		int y=e[i].to;
		if(!dfs1(y,x))ans1-=e[i].w;
		else c++;
		ans2+=1ll*e[i].w*min(sz[y],n-sz[y]);
		sz[x]+=sz[y];
	}
	return (c&1)^1;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);n<<=1;
		for(int i=1;i<=n;++i)head[i]=0;
		cnt=0;
		ans1=ans2=0;
		for(int i=1,x,y,w;i<n;++i){
			scanf("%d%d%d",&x,&y,&w);
			in(x,y,w);
			in(y,x,w);
			ans1+=w;
		}
		dfs1(1);
		cout<<ans1<<" "<<ans2<<endl;
		
	}
}
/*
2
3
1 2 3
3 2 4
2 4 3
4 5 6
5 6 5
2
1 2 1
1 3 2
1 4 3
*/