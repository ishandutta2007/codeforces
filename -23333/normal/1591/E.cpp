#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
const int N=1e6+10;
int a[N],p[N],n,q,ans[N];
vector<int> ve[N];
set<int> SS[N];
struct re{
	int a,b,c;
};
vector<re> Q[N];
int cnt[N];
#define mid ((h+t)/2)
struct sgt{
	int sum[N*4];
	void g(int x,int h,int t,int pos,int k)
	{
		if (h==t) {sum[x]+=k; return;}
		if (pos<=mid) g(x*2,h,mid,pos,k);
		else g(x*2+1,mid+1,t,pos,k);
		sum[x]=sum[x*2]+sum[x*2+1];
    }
    int q(int x,int h,int t,int h1,int t1,int &k)
    {
    	if (h==t)
    	{
    		if (k<=sum[x])
    		{
    			k=0; return h;
    		}
    		k-=sum[x];
    		return 0;
		}
    	if (h1<=h&&t<=t1)
    	{
    		if (sum[x*2]>=k) return q(x*2,h,mid,h1,t1,k);
			else
			{
			  k-=sum[x*2]; 
			  return q(x*2+1,mid+1,t,h1,t1,k);
		    }
    	}
    	int ans=0;
    	if (h1<=mid) ans=q(x*2,h,mid,h1,t1,k);
    	if (mid<t1&&k) ans=q(x*2+1,mid+1,t,h1,t1,k);
    	return ans;
	}
}S;
void dfs(int x,int y)
{
	if (cnt[a[x]])
	{  
	  S.g(1,1,n,cnt[a[x]],-1);
	  SS[cnt[a[x]]].erase(a[x]);
    }
	cnt[a[x]]++;
	SS[cnt[a[x]]].insert(a[x]);
	S.g(1,1,n,cnt[a[x]],1);
	for (auto v:Q[x])
	{
	//	cerr<<S.q(1,1,n,v.a,n,v.b)<<endl;
		ans[v.c]=*SS[S.q(1,1,n,v.a,n,v.b)].begin();
	} 
	for (auto v:ve[x])
	  if (v!=y)
	  {
	  		dfs(v,x);
	  }
	S.g(1,1,n,cnt[a[x]],-1);
	SS[cnt[a[x]]].erase(a[x]); cnt[a[x]]--;
	if (cnt[a[x]])
	{ 
	  S.g(1,1,n,cnt[a[x]],1);
	  SS[cnt[a[x]]].insert(a[x]);
    }
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	SS[0].insert(-1);
	while (T--)
	{
		cin>>n>>q;
		rep(i,1,n) cin>>a[i];
		rep(i,2,n)
		{
			cin>>p[i];
			ve[p[i]].push_back(i);
		}
		rep(i,1,q)
		{
			int x,y,z;
			cin>>x>>y>>z;
			Q[x].push_back((re){y,z,i});
		}
		dfs(1,0);
		rep(i,1,n) ve[i].clear(),Q[i].clear(),SS[i].clear(),cnt[i]=0;
		rep(i,1,n*4) S.sum[i]=0;
		rep(i,1,q) cout<<ans[i]<<" ";
		cout<<"\n";
    }
	return 0;
}