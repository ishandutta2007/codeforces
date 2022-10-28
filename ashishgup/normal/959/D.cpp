#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e6+5;

int n;
int a[N], b[N], sieve[N], prime[N], used[N];
queue<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	fill(sieve+2, sieve+N, 1);
	for(int i=2;i<N;i++)
	{
		if(sieve[i])
		{
			for(int j=1;i*j<N;j++)
			{
				sieve[i*j]=0;
				prime[i*j]=i;
			}
			sieve[i]=1;
			s.push(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cur=a[i];
		vector<int> v;
		while(cur!=1)
		{
			if(used[prime[cur]])
			{
				for(int j=a[i];;j++)
				{
					int check=1;
					int cur=j;
					while(cur!=1)
					{
						if(used[prime[cur]])
							check=0;
						cur/=prime[cur];
					}
					if(!check)
						continue;
					b[i]=j;
					cur=j;
					while(cur!=1)
					{
						used[prime[cur]]=1;
						cur/=prime[cur];
					}
					break;
				}
				for(int j=i+1;j<=n;j++)
				{
					while(used[s.front()])
						s.pop();
					b[j]=s.front();
					s.pop();
				}
				for(int j=1;j<=n;j++)
				{
					cout<<b[j]<<" ";
				}
				return 0;
			}
			else
			{				
				v.push_back(prime[cur]);
			}
			cur/=prime[cur];
		}
		for(auto it:v)
			used[it]=1;
		b[i]=a[i];
	}		
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}