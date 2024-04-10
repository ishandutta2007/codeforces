#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int x, p, k;
int sieve[N];
vector<int> divisors[N];

void preprocess()
{
	for(int i=2;i<N;i++)
	{
		if(!sieve[i])
		{
			for(int j=1;i*j<N;j++)
			{
				sieve[i*j]=1;
				divisors[i*j].push_back(i);
			}
		}
	}
}

int calc(int cur, int prod)
{
	int tot=cur/prod;
	int sub=x/prod;
	return tot-sub;
}

int check(int cur)
{
	int ans=0;
	int sz=divisors[p].size();
	for(int i=1;i<(1<<sz);i++)
	{
		int prod=1, ct=0;
		for(int j=0;j<sz;j++)
		{
			if(i&(1<<j))
			{
				prod*=divisors[p][j];
				ct++;
			}
		}
		if(ct%2)
			ans+=calc(cur, prod);
		else
			ans-=calc(cur, prod);
	}
	int coprime=cur-x-ans;
	return (coprime>=k);
}	

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
    IOS;
    preprocess();
    int t;
    cin>>t;
    while(t--)
    {	
    	cin>>x>>p>>k;
    	int ans=binsearch(1, 1e9);
    	cout<<ans<<endl;
    }	
    return 0;
}