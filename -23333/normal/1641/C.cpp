#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
set<int> S;
int n,q;
#define mid ((h+t)/2)
struct sgt{
	int v[N*4];
	void g(int x,int h,int t,int pos,int k)
	{
		v[x]=max(v[x],k);
		if (h==t) return;
		if (pos<=mid) g(x*2,h,mid,pos,k);
		else g(x*2+1,mid+1,t,pos,k);
	}
	int q(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return v[x];
		int ans=0;
		if (h1<=mid) ans=q(x*2,h,mid,h1,t1);
		if (mid<t1) ans=max(ans,q(x*2+1,mid+1,t,h1,t1));
		return ans;
	}
}SS;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	rep(i,1,n+1) S.insert(i);
    while (q--)
	{
		int tt,l,r,p;
		cin>>tt;
		if (tt==0)
		{
			cin>>l>>r>>p;
			if (p==0)
			{
			  while (1)
			  {
				auto it=S.lower_bound(l);
				if (it!=S.end()&&(*it)<=r)
				{
					S.erase(it);
				} else break;
			  }
		    } else
			{
				SS.g(1,1,n,r,l);
		    }
		} else
		{
			cin>>p;
			auto it=S.lower_bound(p);
			if (it!=S.end()&&(*it)==p)
			{
				auto it=S.upper_bound(p);
				int r=(*it)-1;
				int gg=SS.q(1,1,n,p,r);
				int l=1;
				--it;
				if (it!=S.begin())
				{
					  l=*(--it)+1;
				}
				if (gg>=l) cout<<"YES"<<endl;
				else cout<<"N/A"<<endl;
			} else cout<<"NO"<<endl;
		}
    }
	return 0; 
}