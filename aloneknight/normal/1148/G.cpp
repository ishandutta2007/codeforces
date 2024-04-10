#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
const int N=110000,M=11000000;
int n,k,cc,a[N],vis[M],pr[M],lst[M],mu[M];
pair<int,int>p[N];vector<int>A,B,C[N],d[N];
inline void pre(int x)
{
	mu[1]=1;
	for(int i=2;i<=x;i++)
	{
		if(!vis[i]){pr[++cc]=i;lst[i]=cc;mu[i]=-1;}
		for(int j=1;j<=cc&&1ll*i*pr[j]<=x;j++)
		{
			int t=i*pr[j];vis[t]=1;lst[t]=j;
			if(i%pr[j]==0){mu[t]=0;break;}
			mu[t]=-mu[i];
		}
	}
}
void add(int x,int c,int y)
{
	if(c==d[x].size()){vis[y]+=mu[y];return;}
	add(x,c+1,y);add(x,c+1,y*d[x][c]);
} 
void del(int x,int c,int y)
{
	if(c==d[x].size()){vis[y]-=mu[y];return;}
	del(x,c+1,y);del(x,c+1,y*d[x][c]);
} 
int qry(int x,int c,int y)
{
	if(c==d[x].size())return vis[y];
	return qry(x,c+1,y)+qry(x,c+1,y*d[x][c]);
}
void sol(int l,int r,vector<int>v)
{
	if(v.empty())return ;
	if(l==r){C[l]=v;return;}
	vector<int>L,R;int mid=l+r>>1;
	for(int i=l;i<=mid;i++)add(A[i],0,1);
	for(auto i:v)if(qry(i,0,1))L.pb(i);else R.pb(i);
	for(int i=l;i<=mid;i++)del(A[i],0,1);
	sol(l,mid,L),sol(mid+1,r,R);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	pre(1e7);memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		while(x!=1){int y=pr[lst[x]];d[i].pb(y);while(x%y==0)x/=y;}
		if(!qry(i,0,1))A.pb(i),add(i,0,1);else B.pb(i);
	}
	if(A.size()>=k){for(int i=0;i<k;i++)printf("%d ",A[i]);return 0;}
	for(auto x:A)del(x,0,1);
	sol(0,A.size()-1,B);
	for(int i=0;i<A.size();i++)p[i]=make_pair(C[i].size(),i);
	int sum=0;sort(p,p+A.size());reverse(p,p+A.size());
	for(int i=0;i<A.size();i++)
	{
		sum+=p[i].X+1;
		if(sum>=k)
		{
			int nd=k-(i+1)*2;vector<int>ans;
			for(int j=0;j<=i;j++)
			{
				int x=min(p[j].X-1,nd);nd-=x;x++;ans.pb(A[p[j].Y]);
				for(int k=0;k<x;k++)ans.pb(C[p[j].Y][k]);
			}
			for(auto x:ans)printf("%d ",x);return 0;
		}
	}
	return 0;
}