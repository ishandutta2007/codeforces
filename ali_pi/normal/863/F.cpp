#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+1;
const int inf = 0x3f3f3f3f;

int n,m,Q,head[N],cnt=1,mn[N],mx[N],s,t,tm,d[N],pre[N];

struct nd{
	int ne,to,w,f;
}e[N*4];

void in(int x,int y,int w,int f){
	e[++cnt].to=y;e[cnt].w=w;e[cnt].f=f;e[cnt].ne=head[x];head[x]=cnt;
	e[++cnt].to=x;e[cnt].w=0;e[cnt].f=-f;e[cnt].ne=head[y];head[y]=cnt;
}

queue<int>q;
bool bfs(){
	for(int i=1;i<=t;++i)d[i]=inf;
	d[s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
//		cout<<1;
		for(int i=head[x];i;i=e[i].ne){
			int y=e[i].to;
			if(d[y]>d[x]+e[i].f&&e[i].w>0){
				d[y]=d[x]+e[i].f;
				pre[y]=i;
				q.push(y);
			}
		}
	}
	return d[t]!=inf;
}

int dinic(){
	int flow=inf;
	for(int i=pre[t];i;i=pre[e[i^1].to])
	flow=min(e[i].w,flow);
	for(int i=pre[t];i;i=pre[e[i^1].to])
	e[i^1].w+=flow,e[i].w-=flow;
	return flow*d[t];
}



int main(){
	cin>>n>>Q;
	for(int i=1;i<=n;++i)mx[i]=n;
	for(int i=1;i<=n;++i)mn[i]=1;
	for(int i=1,tp,l,r,w;i<=Q;++i){
	        cin>>tp>>l>>r>>w;
		if(tp==1){
			for(int i=l;i<=r;++i)mn[i]=max(mn[i],w);
		}
		else{
			for(int i=l;i<=r;++i)mx[i]=min(mx[i],w);
		}
	}
	for(int i=1;i<=n;++i)
	if(mn[i]>mx[i])return 0*printf("-1");
	int ans=0;
	s=n*2+1,t=n*2+2;
	for(int i=1;i<=n;++i)in(s,i,1,0);
	for(int i=1;i<=n;++i)
	for(int j=mn[i];j<=mx[i];++j){
		in(i,j+n,1,0);
	}
	for(int i=n+1;i<=2*n;++i)
	for(int j=1;j<=n;++j)
	in(i,t,1,j*2-1);
	while(bfs())
		ans+=dinic();
	cout<<ans;
        return 0;
}