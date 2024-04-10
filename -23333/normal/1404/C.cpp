#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define mid ((h+t)>>1)
const int N=6e5;
const int INF=1e9;
int a[N],ans[N];
    int n,q;
struct re{
	int a,b,c;
}b[N];
bool cmp(re x, re y)
{
	return x.a>y.a;
}
int v[N*4],v2[N*4],lazy[N*4];
inline void down(int x)
{
	v[x*2]+=lazy[x]; v[x*2+1]+=lazy[x];
	lazy[x*2]+=lazy[x]; lazy[x*2+1]+=lazy[x];
	lazy[x]=0; 
}
void insert(int x,int h,int t,int pos,int k)
{
	if (h==t)
	{
		v[x]=k; return ;
	}
	down(x);
	if (pos<=mid) insert(x*2,h,mid,pos,k);
	else insert(x*2+1,mid+1,t,pos,k);
	v[x]=min(v[x*2],v[x*2+1]); 
}
void change(int x,int h,int t,int pos,int k)
{
	if (h==t)
	{
		v2[x]=k; return ;
	}
	if (pos<=mid) change(x*2,h,mid,pos,k);
	else change(x*2+1,mid+1,t,pos,k);
	v2[x]=v2[x*2]+v2[x*2+1]; 
}
int query(int x,int h,int t,int h1,int t1)
{
	if (h1<=h&&t<=t1) return v2[x];
	int ans=0;
	if (h1<=mid) ans=query(x*2,h,mid,h1,t1);
	if (mid<t1) ans+=query(x*2+1,mid+1,t,h1,t1);
	return ans;
}
void gg(int x,int h,int t,int h1,int t1,int kk)
{
	if (h1<=h&&t<=t1)
	{
		v[x]+=kk; lazy[x]+=kk; return;
	}
	down(x);
	if (h1<=mid) gg(x*2,h,mid,h1,t1,kk);
	if (mid<t1) gg(x*2+1,mid+1,t,h1,t1,kk);
	v[x]=min(v[x*2],v[x*2+1]);
}
vector<int> ve;
void cz(int x,int h,int t)
{
	down(x);
		if (v[x]!=0) return;
		if (h==t)
		{
			ve.push_back(h); return;
		}
		if (v[x*2]==0) cz(x*2,h,mid);
		if (v[x*2+1]==0) cz(x*2+1,mid+1,t);
}
void cl(int x)
{
	if (x+1<=n) gg(1,1,n,x+1,n,-1);
	ve.clear();
	cz(1,1,n);
	vector<int> ve2;
	ve2.assign(ve.begin(),ve.end());
	int nn=ve.size();
	rep(i,0,nn-1)
	{
		insert(1,1,n,ve2[i],INF);
		change(1,1,n,ve2[i],1);
	}
	rep(i,0,nn-1) cl(ve2[i]); 
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n) cin>>a[i];
    rep(i,1,q)
    {
    	cin>>b[i].a>>b[i].b;
    	b[i].a++; b[i].b=n-b[i].b;
    	b[i].c=i;
    }
    sort(b+1,b+q+1,cmp);
    rep(i,1,n) insert(1,1,n,i,INF);
    int now=1;
    dep(i,n,1)
    {
    	if (a[i]==i)
    	{
    		change(1,1,n,i,1);
    		cl(i);
    	} else
    	if (a[i]<i) insert(1,1,n,i,i-a[i]);
    	while (b[now].a==i)
    	{
    		int t=query(1,1,n,b[now].a,b[now].b);
    		ans[b[now].c]=t;
    		now++;
    	}
    }
    rep(i,1,q) cout<<ans[i]<<endl;
	return 0;
}