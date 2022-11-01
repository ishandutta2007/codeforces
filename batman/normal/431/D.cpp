#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)65)
#define K ((ll)11)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll m,k,c[N][N];

ll count(ll x)
{
	ll res=0,now=k;
	stack <ll> s;
	while(x)s.push(x%2),x/=2;
	while(s.size() && now>=0)
	{
		ll p=s.top();s.pop();
		if(!p)continue;
		res+=c[s.size()][now];
		now--;
	}
	return res;
}

int main()
{
	for(int i=0;i<N;i++)c[i][0]=c[i][i]=1;
	for(int i=1;i<N;i++)for(int j=1;j<i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
	cin>>m>>k;
	ll l=0,r=INF;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(count(2*mid)-count(mid)>=m)r=mid;
		else l=mid;
	}
	cout<<r;
	return 0;
}