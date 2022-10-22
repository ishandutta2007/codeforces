#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int a[N],gggg[N];
struct re{
	int a,b;
}b[N],c[N];
bool cmp(re x,re y)
{
	if (x.a!=y.a) return x.a<y.a;
	return x.b<y.b;
}
map<int,int> M,M2;
vector<int> ve[N];
int p2[N];
re p[N*10];
struct re2{
	int a,b,c,d;
};
vector<re2> q[N];
#define lowbit(x) (x&(-x))
struct sgt{
  int a[N];
  void g(int x)
  {
  	while (x<=n)
  	{
  		a[x]++;
  		x+=lowbit(x);
  	}
  }
  int q(int x)
  {
  	int ans=0;
  	while(x>0)
	{
		ans+=a[x];
		x-=lowbit(x);
    }
    return ans;
  }
}S;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m; M.clear();
		rep(i,1,n) ve[i].clear();
		int cnt=0;
		rep(i,1,n)
		{ 
		  cin>>a[i];
		  if (!M[a[i]]) M[a[i]]=++cnt;
	    }
	    rep(i,1,n)
	      ve[M[a[i]]].push_back(i);
		rep(i,1,m)
		{
			cin>>b[i].a>>b[i].b;
			c[i]=b[i];
		}
		sort(b+1,b+m+1,cmp);
		int now=0;
		int sum=0;
		rep(i,1,m)
		{
		  if (b[i].b<=now) continue;
		  rep(j,max(b[i].a,now+1),b[i].b)
		  {
		  	auto g=ve[M[a[j]]];
		  	auto it=lower_bound(g.begin(),g.end(),j);
		  	if (it!=g.begin())
			{ 
			    it--;
			    if (*it>=b[i].a) p[++sum]={*it,j};
			}
			it=lower_bound(g.begin(),g.end(),b[i].a);
			if (*it!=j)
			{
				p[++sum]={*it,j};
			}
		  }
		  now=b[i].b;
	    }
	    rep(i,1,n) p2[i]=0,q[i].clear(),gggg[i]=0;
	    rep(i,1,sum) p2[p[i].a]=max(p[i].b,p2[p[i].a]);
	    int gg=0;
	    rep(i,1,n) if(p2[i]) gg=i;
	    int ans3=n;
	    rep(i,1,sum) ans3=min(ans3,p[i].b);
	    int ans2=0,ans=1e9;
	    rep(i,1,ans3)
	    {
	      ans=min(ans,max(ans2,gg)-i+1);
	      ans2=max(ans2,p2[i]);
	    }
	    if (sum==0) ans=0;
	    cout<<ans<<endl;
//	    rep(i,1,n) S.a[i]=0;
	}
	return 0;
}