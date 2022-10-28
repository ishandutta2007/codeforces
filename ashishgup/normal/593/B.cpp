#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
double x1, x2;
pair<int, int> v[N];

int32_t main()
{
	IOS;
	cin>>n>>x1>>x2;
	for(int i=1;i<=n;i++)
	{
		int k, b;
		cin>>k>>b;
		v[i].first=x1 * k + b;
		v[i].second=x2 * k + b;
	}
	sort(v+1, v+n+1);
	int current=0;
	int currenty=0;
	for(int i=1;i<=n-1;i++)
	{		
		if(v[i+1].second < v[i].second)
		{
			cout<<"YES";
			return 0;
		}
	}	
	cout<<"NO";
	return 0;
}