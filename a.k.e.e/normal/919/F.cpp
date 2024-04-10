#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <assert.h>

using namespace std;

typedef long long ll;
const int MAXN=300005;

int m;
struct State
{
	int a[8],b[8];
	State(){memset(a,0,sizeof(a));memset(b,0,sizeof(b));}
	vector<int> play()const;
	State fair()const;
	int rank()const;
	int condi()const;
}x[MAXN];
int hal[505][8];

bool operator <(State u,State v)
{
	for(int i=0;i<8;i++)
		if(u.a[i]!=v.a[i])return u.a[i]<v.a[i];
	for(int i=0;i<8;i++)
		if(u.b[i]!=v.b[i])return u.b[i]<v.b[i];
	return 0;
}
vector<int> State::play()const
{
	bool vis[5];memset(vis,0,sizeof(vis));
	for(int i=0;i<8;i++)vis[b[i]]=1;
	vector<int> res;
	State s;
	memcpy(s.a,b,sizeof(s.a));
	memcpy(s.b,a,sizeof(s.b));
	for(int i=1;i<5;i++)
	{
		if(!vis[i])continue;
		for(int j=0;j<8;j++)
		{
			if(!s.b[j])continue;
			s.b[j]=(s.b[j]+i)%5;
			res.push_back(s.fair().rank());
			s.b[j]=(s.b[j]-i+5)%5;
		}
	}
	sort(res.begin(),res.end());
	unique(res.begin(),res.end());
	return res;
}
State State::fair()const
{
	State s=*this;
	sort(s.a,s.a+8);
	sort(s.b,s.b+8);
	return s;
}
int State::rank()const
	{return lower_bound(x+1,x+m*m+1,*this)-x;}
State nstate(int x,int y)
{
	State res;
	memcpy(res.a,hal[x],sizeof(res.a));
	memcpy(res.b,hal[y],sizeof(res.b));
	return res;
}

int curh[8];
void gethal(int lenh)
{
	if(lenh==7)
	{
		memcpy(hal[++m],curh,sizeof(curh));
		return;
	}
	for(int i=curh[lenh];i<5;i++)
	{
		curh[lenh+1]=i;
		gethal(lenh+1);
	}
}
int q[MAXN],ind[MAXN],win[MAXN];
struct Edge
{
	int v;
	Edge *next;
}pool[MAXN<<5|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v)
{
	Edge *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int front=1,rear=0;
    vector<int> v;
    for(int i=0;i<5;i++)
    	{curh[0]=i;gethal(0);}
    for(int i=1;i<=m;i++)
    	for(int j=1;j<=m;j++)
    		x[(i-1)*m+j]=nstate(i,j);
    for(int i=1;i<=m*m;i++)
    {
    	v=x[i].play();
    	ind[i]=v.size();
    	for(int j=0;j<v.size();j++)
    		addEdge(v[j],i);
    	bool flag=1;
    	for(int j=0;j<8;j++)
    		if(x[i].b[j]){flag=0;break;}
    	if(flag){ind[i]=0;q[++rear]=i;win[i]=-1;}
    }
    while(front<=rear)
    {
    	int u=q[front++];
    	for(Edge *p=h[u];p;p=p->next)
    	{
    		if(!ind[p->v] || win[p->v])continue;
    		if(win[u]<0)win[p->v]=1;
    		else --ind[p->v];
    		if(!ind[p->v] || win[p->v])
    		{
    			if(!win[p->v])win[p->v]=-1;
    			ind[p->v]=0;
    			q[++rear]=p->v;
    		}
    	}
    }
    int T,who;
    State s;
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%d",&who);
    	if(!who)
    	{
	    	for(int i=0;i<8;i++)scanf("%d",&s.a[i]);
	    	for(int i=0;i<8;i++)scanf("%d",&s.b[i]);
	    }
	    else
	    {
	    	for(int i=0;i<8;i++)scanf("%d",&s.b[i]);
	    	for(int i=0;i<8;i++)scanf("%d",&s.a[i]);
	    }
	    s=s.fair();
	    int t=win[s.rank()];
	    if(!t)printf("Deal\n");
	    else if(t<0)printf(who?"Alice\n":"Bob\n");
	    else printf(who?"Bob\n":"Alice\n");
    }
    return 0;
}