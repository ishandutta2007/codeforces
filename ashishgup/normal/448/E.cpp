#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5;

int n, k, toprint=N;
vector<int> divisors;
vector<int> indivisors[N];

void recurse(int x, int lvl)
{
	if(toprint==0)
		exit(0);
	if(x==0)
	{
		toprint--;
		cout<<divisors[x]<<" ";
		return;
	}
	if(lvl==k)
	{
		toprint--;
		cout<<divisors[x]<<" ";
		return;
	}
	for(auto it:indivisors[x])
		recurse(it, lvl+1);
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	if(n==1)
		cout<<"1";
	else if(k>N)
	{
		k=N;
		while(k--)
			cout<<"1 ";
	}
	else
	{	
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				divisors.push_back(i);
				if(i != n/i)
					divisors.push_back(n/i);
			}
		}
		sort(divisors.begin(), divisors.end());
		int sz=divisors.size();
		for(int i=0;i<sz;i++)
			for(int j=0;j<=i;j++)
				if(divisors[i]%divisors[j]==0)
					indivisors[i].push_back(j);
		recurse(divisors.size()-1, 0);
	}
	return 0;
}