#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N];
vector<int> c, d;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	if(a[1]!=b[1] || a[n]!=b[n])
	{
		cout<<"No";
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		c.push_back(a[i]-a[i-1]);
		d.push_back(b[i]-b[i-1]);
	}
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	if(c==d)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}