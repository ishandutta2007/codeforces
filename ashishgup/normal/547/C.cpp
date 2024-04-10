#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, q, have=0, ans=0;
int a[N], sieve[N], prime[N], f[N], freq[N];

void precompute()
{
	fill(sieve+1, sieve+N, 1);
	sieve[1]=0;
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<N;j++)
			{
				sieve[i*j]=0;
				prime[i*j]=i;
			}
		}
	}
}

int32_t main()
{
	precompute();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(q--)
	{
		int x;
		cin>>x;
		int store=x;
		have-=f[x];
		f[x]^=1;
		have+=f[x];
		set<int> s;
		x=a[x];
		while(x>1)
		{
			int cur=prime[x];
			s.insert(cur);
			x/=cur;
		}
		x=store;
		vector<int> v;
		for(auto &it:s)
			v.push_back(it);
		int sz=v.size();
		for(int i=1;i<(1<<sz);i++)
		{
			int val=1;
			for(int j=0;j<sz;j++)
			{
				if((i>>j)&1)
					val*=v[j];
			}
			if(f[x]==0)
				freq[val]--; 
			if((__builtin_popcount(i)%2)^f[x])
				ans-=freq[val];
			else
				ans+=freq[val];
			if(f[x]==1)
				freq[val]++;
		}
		cout<<(have*(have-1)/2)-ans<<endl;
	}
	return 0;
}