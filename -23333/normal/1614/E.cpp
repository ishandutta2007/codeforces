#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2.1e5;
#define mid ((h+t)/2)
struct sgt{
	int lazy[N*80],mx[N*80],mn[N*80],ls[N*80],rs[N*80],cnt;
	inline void sc(int &x,int h,int t)
	{
		x=++cnt;
		mn[x]=h; mx[x]=t;
	}
	inline void gg(int x,int y)
	{
		mn[x]+=y; mx[x]+=y; lazy[x]+=y;
	}
	inline void updata(int x)
	{
		mx[x]=mx[rs[x]];
		mn[x]=mn[ls[x]];
	}
	inline void down(int x,int h,int t)
	{
		if(!ls[x]) sc(ls[x],h,mid); 
		if(!rs[x]) sc(rs[x],mid+1,t);
		if (lazy[x])
		{
			gg(ls[x],lazy[x]); gg(rs[x],lazy[x]);
			lazy[x]=0;
		} 
	}
	void g(int &x,int h,int t,int h1,int t1,int k)
	{
		if(h1<=h&&t<=t1)
		{
			//cerr<<x<<" "<<h<<" "<<t<<" "<<k<<endl;
			gg(x,k); return;
		}
        down(x,h,t);
		if (h1<=mid) g(ls[x],h,mid,h1,t1,k);
		if (mid<t1) g(rs[x],mid+1,t,h1,t1,k);
		updata(x);
	}
	int q(int &x,int h,int t,int pos)
	{
	//	cerr<<x<<" "<<h<<" "<<t<<endl;
		if (h==t) return mn[x];
		down(x,h,t);
		if(pos<=mid) return q(ls[x],h,mid,pos);
		else return q(rs[x],mid+1,t,pos);
	}
	int q1(int x,int h,int t,int k1)
	{
		if (h==t)
		{
			if (mn[x]>=k1) return h-1;
			else return h;
		}
		down(x,h,t);
		if (mn[rs[x]]<k1) return q1(rs[x],mid+1,t,k1);
		else return q1(ls[x],h,mid,k1);
	}
	
	int q2(int x,int h,int t,int k1)
	{
		if (h==t)
		{
			if (mx[x]<=k1) return h+1;
			else return h;
		}
		down(x,h,t);
		if (mx[ls[x]]>k1) return q2(ls[x],h,mid,k1);
		else return q2(rs[x],mid+1,t,k1);
	}
}S;
const int mo=1e9+1;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int ans=0;
	int rt=0;
	S.sc(rt,0,1e9); 
	rep(i,1,n)
	{
		int T,K;
		cin>>T;
		int X1=S.q1(rt,0,1e9,T);
		int X2=S.q2(rt,0,1e9,T);
		if (X1>=0) S.g(rt,0,1e9,0,X1,1);
		if (X2<=1e9) S.g(rt,0,1e9,X2,1e9,-1);
		cin>>K;
		rep(i,1,K)
		{
			int x;
			cin>>x;
			x=(x+ans)%mo;
			ans=S.q(rt,0,1e9,x);
			cout<<ans<<"\n";
		}
	}
	return 0;
}