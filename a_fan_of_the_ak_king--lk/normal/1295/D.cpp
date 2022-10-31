#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int t;
long long a,m;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		cin>>a>>m;
		m/=__gcd(a,m);
		long long s=m;
		for(long long i=2;i*i<=m;++i)
			if(m%i==0)
			{
				while(m%i==0)
					m/=i;
				s=s/i*(i-1);
			}
		if(m!=1)
			s=s/m*(m-1);
		cout<<s<<endl;
	}
}