#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, cur=0, ans=0;
int a[N], b[N];
vector<int> diff;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		cur+=a[i];
		diff.push_back(a[i]-b[i]);
	}
	sort(diff.begin(), diff.end());
	while(diff.size() && cur>m)
	{
		cur-=diff.back();
		diff.pop_back();
		ans++;
	}
	if(cur>m)
		ans=-1;
	cout<<ans;
	return 0;
}