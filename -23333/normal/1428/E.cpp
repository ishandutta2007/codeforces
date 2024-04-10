#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
int n,k;
struct re{
	ll a,b,c;
};
struct cmp{
	bool operator () (re x,re y)
	{
		return x.b<y.b;
	}
};
priority_queue<re,vector<re>,cmp> Q;
ll js(int x,int y)
{
	ll k=x/y;
	ll k1=x%y;
	return k1*(k+1)*(k+1)+(y-k1)*k*k;
}
ll a[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,k; 
	cin>>n>>k;
	ll ans=0;
	rep(i,1,n)
	{ 
	  cin>>a[i];
	  ans+=1ll*a[i]*a[i];
	  if (a[i]>1) Q.push((re){i,1ll*a[i]*a[i]-js(a[i],2),2});
    }
    rep(i,1,k-n)
    {
    	re x=Q.top(); Q.pop();
    	ans-=x.b;
    	if (x.c<a[x.a]) Q.push((re){x.a,js(a[x.a],x.c)-js(a[x.a],x.c+1),x.c+1}); 
    }
    cout<<ans<<endl;
	return 0; 
}