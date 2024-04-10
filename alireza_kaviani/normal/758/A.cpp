#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;

int main()
{
	int n;
	cin >> n;
	int a[n];
	
	int maxn=0;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		maxn=max(maxn,a[i]);
	}
	
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=maxn-a[i];
	}
	cout << ans ;
	
	
}