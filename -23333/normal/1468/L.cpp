#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)

typedef long long ll;
const int N=5e5;
ll a[N],pos[N];
map<ll,int> M;
bool P[N];
int cnt;
vector<int> ve[N];
const int MAXN = 100005;
const int p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
typedef long double ld;
ll times(ll a, ll b, ll P) {
  ll tmp = (ld) a * b / P;
  return ((a * b - tmp * P) % P + P) % P;
}
ll mns(ll a, ll b) {
  if (a >= b) return a - b;
  else return b - a;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}
ll power(ll a, ll b, ll P) {
  if (b == 0) return 1;
  ll tmp = power(a, b / 2, P);
  if (b % 2 == 0) return times(tmp, tmp, P);
  else return times(a, times(tmp, tmp, P), P);
}
bool prime(ll n) {
  for (int i = 0; i <= 8; i++) {
      if (p[i] == n) return true;
      else if (p[i] > n) return false;
      ll tmp = power(p[i], n - 1, n), tnp = n - 1;
      if (tmp != 1) return false;
      while (tmp == 1 && tnp % 2 == 0) {
          tnp /= 2;
          tmp = power(p[i], tnp, n);
          if (tmp == n - 1) break;
          if (tmp != 1) return false;
      }
  }
  return true;
}
ll check(ll x,ll y)
{
	__int128 ans=1;
	rep(i,1,y)
	{
	  ans=ans*x;
	  if (ans>1e18) return 1e18;
    }
    ll ans2=ans;
    return ans2;
}
			int MM[10000];
int main()
{
	ios::sync_with_stdio(false);
//	cout<<1ll*998244353*998244353<<endl;
	int n,m;
	cin>>n>>m;
    if (m==1)
    {
    	cout<<0<<endl;
    	exit(0);
    }
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		int ii=i;
		rep(j,2,1000)
	    {
	    	__int128 now=1;
	    	while (now<a[i])
	    	{
	    		now*=j;
	    	}
	    	if (now==a[i])
	    	{
	    	    if (!M[j]) {M[j]=++cnt; pos[cnt]=j;}
	    		ve[M[j]].push_back(i);
	    	}
	    }
	    rep(i,1,6)
	    {
	    	int h=1,t=1e9; 
	    	int ans2=0;
	    	while (h<=t)
	    	{
	    		int mid=(h+t)/2;
	    		ll ans=check(mid,i);
	    		if (ans>a[ii]) t=mid-1;
	    		if (ans<a[ii]) h=mid+1;
	    		if (ans==a[ii]) {ans2=mid; break;}
	    	}
	    	if (ans2>1000)
	    	{ 
	    		if (!M[ans2]) {M[ans2]=++cnt; pos[cnt]=ans2;}
	    		ve[M[ans2]].push_back(ii);
	        }
	    }
	}
	vector<int> ans,h;
	int ans2=0,gg=0;
	rep(i,1,cnt)
	  if (ve[i].size()>=2&&prime(pos[i]))
	  {
	  	for (auto v:ve[i]) ans.push_back(v),P[v]=1;
	  	if (ve[i].size()>2) gg=i;
	  	ans2+=ve[i].size();
	  	h.push_back(pos[i]);
	  }
	if (ans2<m)
	{
		rep(i,1,n)
		  if (!P[i])
		  {
		  	ll now=a[i];
		  	for (auto v:h)
		  	  while (now%v==0) now/=v;
		  	if (now==1) ans.push_back(i);
		  }
		if (ans.size()>=m)
		{
			rep(i,0,m-1) cout<<a[ans[i]]<<" ";
			cout<<endl;
		} else
		cout<<0<<endl;
	} else
	if (gg)
	{
		vector<int> ans;
		rep(i,1,cnt)
		  if (i!=gg&&ve[i].size()>=2&&prime(pos[i]))
		    if (m>ve[i].size()&&ve[i].size()+1!=m)
		    {
		    	for (auto v:ve[i]) ans.push_back(v);
		    	m-=ve[i].size();
		    } else
		    {
		    	int t=m;
		    	if (t+1==ve[i].size()) t=max(m-3,0);
		    	if (ve[i].size()+1==m) t=max(m-2,0);
		    	if (t==1) t=0;
		    	for (int j=0;j<t;j++) ans.push_back(ve[i][j]);
		    	m-=t;
		    }
		for (int j=0;j<m;j++) ans.push_back(ve[gg][j]);
//		cout<<ans.size()<<endl;
		for (auto v:ans) cout<<a[v]<<" ";
		cout<<endl;
	} else
	{
		int nowcnt=1e9,poss=0;
		rep(i,1,n)
		  if (!P[i])
		  {
		  	ll now=a[i];
		  	int cnt=0;
		  	for (auto v:h)
		  	{
		  	  bool tt=0;
		  	  while (now%v==0) now/=v,tt=1;
		  	  cnt+=tt;
		    }
		    if (now==1&&cnt<nowcnt) {poss=i; nowcnt=cnt;}
		  }
		if (m%2==0||(poss&&nowcnt*2+1<=m))
		{
			ll now=a[poss];
			vector<int> ans; 
			if (m%2==1)
			{
			  m--; 
			  ans.push_back(poss);
		    } else now=1;
		    rep(i,1,cnt)
		      if (ve[i].size()>=2&&prime(pos[i]))
			  {
		  	    bool tt=0;
		  	    int v=pos[i];
		  	    while (now%v==0) now/=v,tt=1;
		  	    if (tt)
				{ 
				  MM[i]=1;
		    	  for (auto v:ve[i]) ans.push_back(v);
		    	  m-=2;
		        }
		      }
		    rep(i,1,cnt)
		      if (ve[i].size()>=2&&prime(pos[i])&&!MM[i]&&m)
		      {
		    	  for (auto v:ve[i]) ans.push_back(v);
		    	  m-=2;
		      }
		    for (auto v:ans) cout<<a[v]<<" ";
		} else
		cout<<0<<endl; 
    }
	return 0;
}
/*
3 2
998244353 996491788296388609 3
*/