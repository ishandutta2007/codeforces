#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, k, d;
int a[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n>>k>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	s.insert(n+1);
	for(int i=n;i>=1;i--)
	{
		auto it=s.lower_bound(i+k);
		if(i+k-1<=n && a[*it - 1]-a[i]<=d)
		{
			s.insert(i);
		}
	}
	if(s.find(1)!=s.end())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}