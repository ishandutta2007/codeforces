#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=4e5;
int n,m;
int a[N];
struct re{
	int a,b;
	bool operator <(const re x)
	{
		if(b!=x.b) return b<x.b;
		return a<x.a;
	}
};
const int mo=998244353;
int f[N*200];
bool t[N];
const int gg=1e5;
int ans=0,cnt;
vector<re> ve[N];
vector<int> er;
bool cmp(re x,re y)
{
	return x.b<y.b;
}
void dfs(int x,int y)
{
	if(t[x]) return;
	t[x]=1; cnt++; er.push_back(x);
	auto it=lower_bound(ve[x].begin(),ve[x].end(),(re){0,y});
	while (it!=ve[x].end()&&(*it).b==y)
	{
	  dfs(it->a,y); it++;
    }
}
void solve()
{
	int m=600;
	rep(i,0,m)
	{
	  rep(j,1,n)
	  {
	  	f[i*j-a[j]+gg]++;
	  	ans=max(ans,f[i*j-a[j]+gg]); 
	  }
	  rep(j,1,n) f[i*j-a[j]+gg]--;
    }
    int m2=170;
    rep(i,1,n)
      rep(j,i+1,min(n,i+m2))
        if (a[j]>a[i]&&(a[j]-a[i])%(j-i)==0&&(a[j]-a[i])/(j-i)>=m)
        {
        	ve[i].push_back({j,(a[j]-a[i])/(j-i)});
        	ve[j].push_back({i,(a[j]-a[i])/(j-i)});
        }
    rep(i,1,n) sort(ve[i].begin(),ve[i].end(),cmp);
    rep(i,1,n)
      for(auto v:ve[i])
      {
      	cnt=0;
        dfs(i,v.b);
        for (auto v:er) t[v]=0;
        er.clear();
        ans=max(ans,cnt);
      }
    rep(i,1,n) ve[i].clear();
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	rep(i,1,n) cin>>a[i];
	solve();
	reverse(a+1,a+n+1);
    solve();
    cout<<n-ans<<endl;
	return 0;
}