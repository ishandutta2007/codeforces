#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=3e5+10;
unordered_map<int,int> M[N];
int n,a[N],b[N];
ll ve0[N],ve1[N],sum0[N],sum1[N],cnt0,cnt1; 
char ss[1<<24],*A=ss,*B=ss;
inline  char gc()
{
  return (A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++);
}
template<class T>void read(T &x)
{
  int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=c^48;
  while (c=gc(),47<c&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f;
}
int main()
{
	ios::sync_with_stdio(false);
    read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) read(b[i]);
	rep(i,2,n) b[i]=b[i]-a[i]; 
	ll ans2=0;
	rep(i,1,n)
	{
		M[i][i]=1;
		ll ans=0;
		for (auto v:M[i])
		if (v.second)
		{
		  for (int j=2*i;j<=n;j+=i)
		  {
		  	M[j][v.first]-=v.second;
		  }
		  if (v.first!=1) ans+=v.second*b[v.first];
		//  assert(v.second>=-1&&v.second<=1);
	    }
	    if (M[i][1]==1) ve0[++cnt0]=ans;else
		if (M[i][1]==-1) ve1[++cnt1]=ans; else
		ans2+=abs(ans);
	}
	sort(ve0+1,ve0+cnt0+1);
	sort(ve1+1,ve1+cnt1+1);
	rep(i,1,cnt0) sum0[i]=sum0[i-1]+ve0[i];
	rep(i,1,cnt1) sum1[i]=sum1[i-1]+ve1[i];
	int q;
	read(q);
	while (q--)
	{
		ll x;
		read(x);
		x-=a[1];
		ll ans3=0;
		int k=lower_bound(ve0+1,ve0+cnt0+1,-x)-ve0;
		ans3+=-(k-1)*x-sum0[k-1]+(sum0[cnt0]-sum0[k-1])+(cnt0-k+1)*x;
		k=lower_bound(ve1+1,ve1+cnt1+1,x)-ve1;
		ans3+=(k-1)*x-sum1[k-1]+(sum1[cnt1]-sum1[k-1])-(cnt1-k+1)*x;
		cout<<ans3+ans2<<"\n"; 
	} 
	return 0;
}