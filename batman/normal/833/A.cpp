#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)1010)

ll n,prime[N],mul[N],cnt;
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=2;i<N;i++)
		if(!mark[i])
		{
			mul[cnt]=i*i*i;
			prime[cnt++]=i;
			for(int j=2*i;j<N;j+=i)mark[j]=1;
		}
	cin>>n;
	while(n--)
	{
		long long a,b;
		cin>>a>>b;
		if(a==1 && b==1)
		{
			cout<<"Yes\n";
			continue;
		}
		long long x=__gcd(a,b),y=1LL*a*b/x;
		
		if((1LL*x*x)%y)
		{
			cout<<"No\n";
			continue;
		}
		long long z=(1LL*x*x)/y;
		ll l=0,r=N;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(1LL*mid*mid*mid<=z)l=mid;
			else r=mid;
		}
		if(1LL*l*l*l==z)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}