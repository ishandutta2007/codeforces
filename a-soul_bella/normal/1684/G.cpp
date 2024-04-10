#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge
{
	int u,v,fl,c,n;
}e[2000005];
int eid,head[1005],p[1005],v[1005],s=1001,t=1002,ans,n,m,dep[1005],D[1005];
inline void add(int u,int v,int w)
{
	e[++eid]={u,v,0,w,head[u]};
	head[u]=eid;
	e[++eid]={v,u,0,0,head[v]};
	head[v]=eid;
}
inline bool Find()
{
	queue <int> q;
	for(int i=0;i<=t;i++)
		v[i]=dep[i]=0;
	q.push(s);
	v[s]=1;
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].n)
		{
			if(!v[e[i].v]&&e[i].fl<e[i].c)
			{
				p[e[i].v]=i;
				q.push(e[i].v);
				v[e[i].v]=1;
				dep[e[i].v]=dep[x]+1;
				if(e[i].v==t)
					return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int x,int now)
{
	if(x==t||!now)
		return now;
	int t=now;
	for(int i=head[x];i;i=e[i].n)
	{
		if(e[i].c>e[i].fl&&dep[e[i].v]==dep[x]+1)
		{
            int delta=dfs(e[i].v,min(t,e[i].c-e[i].fl));
			if(!delta)
				dep[e[i].v]=0;
            e[i].fl+=delta;
            e[((i-1)^1)+1].fl-=delta;
            t-=delta;
            if(t==0)
				break;
        }
	}
	return now-t;
}
inline void dinic()
{
	while(Find())
		ans+=dfs(s,1000000007);
}
int a[1005];
vector <pair<int,int> > V;
vector <int> qwq;
inline void go(int x,int y)
{
	if(!x||!y) return ;
	if(x<y) swap(x,y);
	x%=y;
	if(x) qwq.push_back(x);
	go(x,y);
}
inline void ins(int x,int y)
{
	go(x,y),V.push_back({x,y});
}
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]*3>m)
		{
			for(int j=1;j<i;j++)
			{
				int x=a[j]+a[i],y=a[i]*2+a[j];
				if(y>m) continue;
				if(y%x!=a[i]) continue;
				y=y%x;
				if(x%y!=a[j]) continue;
				x=x%y;
				if(max(x,y)%min(x,y)) continue;
				add(j,i,1);
			}
			add(i,t,1),++cnt;
		}
		else add(s,i,1);
	}
	dinic();
	if(ans!=cnt)
	{
		cout << "-1";
		return 0;
	}
	for(int i=1;i<=eid;i++)
	{
		if(e[i].fl&&e[i].u<=n&&e[i].v<=n&&e[i].u<e[i].v)
		{
			D[e[i].u]=D[e[i].v]=1;
			int x=a[e[i].u],y=a[e[i].v];
			ins(x+y,x+y+y);
		}
	}
	for(int i=1;i<=n;i++)
		if(!D[i]) ins(a[i]*2,a[i]*3);
	cout << V.size() << "\n";
	for(auto t:V) cout << t.first << " " << t.second << "\n";
//	for(auto t:qwq) cout << t << " ";
	return 0;
}