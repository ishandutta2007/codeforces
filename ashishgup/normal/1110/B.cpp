#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, k, ans=0;
int a[N];
vector<int> diff;

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=2)
			diff.push_back(a[i]-a[i-1]-1);
	}
	ans=a[n]-a[1]+1;
	sort(diff.rbegin(), diff.rend());
	int sz=diff.size();
	for(int i=0;i<min(sz, k-1);i++)
		ans-=diff[i];
	cout<<ans;
	return 0;
}