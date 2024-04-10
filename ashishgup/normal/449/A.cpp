#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int ans=0;

vector<int> factorise(int n)
{
	vector<int> fact;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			fact.push_back(i);
			if(i!=n/i)
			{
				fact.push_back(n/i);
			}
		}
	}
	return fact;
}

int solve(int n, int m, int k)
{
	int curans=0;
	vector<int> div=factorise(n);
	for(auto it:div)
	{
		if(it-1>k)
			continue;
		//Total number of rows and columns = k+2
		int cur=(n/it)  * (m/(k-it+2));
		curans=max(cur, curans);
	}
	return curans;
}

int32_t main()
{
    IOS;
	int n, m, k;
   	cin>>n>>m>>k;
   	int maxcuts=n-1+m-1;
   	if(k>maxcuts)
   		return cout<<"-1", 0;
   	ans=max(solve(n, m, k), solve(m, n, k));
   	cout<<ans;
    return 0;
}