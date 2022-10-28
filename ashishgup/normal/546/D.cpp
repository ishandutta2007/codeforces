#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e6+5;

int a, b;
int sieve[N], val[N];

void precompute()
{
	fill(sieve+2, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<N;j++)
			{
				sieve[i*j]=0;
				val[i*j]+=1;
				int cur=i*i;
				while((i*j)%cur==0)
				{
					val[i*j]+=1;
					cur*=i;
				}
			}
		}
	}
	for(int i=2;i<N;i++)
		val[i]+=val[i-1];
}

int32_t main()
{
	IOS;
	precompute();
	int t;
	cin>>t;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		int ans=val[a]-val[b];
		cout<<ans<<endl;
	}
	return 0;
}