#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n,m,head[N];

struct nd{
	int ne,to,w;
}e[N<<2];

void in(int x,int y,int w){
	static int cnt;
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;e[cnt].w=w;
}

void solve(){
	static int dis[N][51];
	static bool use[N][51];
	priority_queue<pair<int,pair<int,int>>> q;
	memset(dis,0x3f,sizeof(dis));
	dis[1][0]=0;
	q.push(make_pair(-0,make_pair(1,0)));
	while(!q.empty()){
		int x=q.top().second.first,d=q.top().second.second;
		q.pop();
		if(use[x][d])continue;
		use[x][d]=1;
		for(int i=head[x];i;i=e[i].ne){
			int y=e[i].to,nexd,val;
			if(d==0){
				nexd=e[i].w;
				val=0;
			}
			else{
				nexd=0;
				val=(e[i].w+d)*(e[i].w+d);
			}
			if(dis[x][d]+val<dis[y][nexd]){
				dis[y][nexd]=dis[x][d]+val;
				q.push(make_pair(-dis[y][nexd],make_pair(y,nexd)));
			}
		}
	}
	for(int i=1;i<=n;++i)
	if(dis[i][0]==0x3f3f3f3f)printf("-1 ");
	else printf("%d ",dis[i][0]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,w;i<=m;++i){
		scanf("%d%d%d",&x,&y,&w);
		in(x,y,w);
		in(y,x,w);
	}
	solve();
}