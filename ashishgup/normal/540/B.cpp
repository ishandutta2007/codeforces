#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, p, x, y;
int a[N];
int ge=0, lesser=0;
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>k>>p>>x>>y;
	int idx=k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		ge+=(a[i]>=y);
		lesser+=(a[i]<y);
	}
	while(ge<(n+1)/2)
	{
		ans.push_back(y);
		a[++idx]=y;
		ge++;
	}
	while(k + ans.size() < n)
	{
		ans.push_back(1);
		a[++idx]=1;
		lesser++;
	}
	sort(a+1, a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	if(sum<=x && a[(n+1)/2]>=y)
	{
		for(auto &it:ans)
			cout<<it<<" ";
	}
	else
		cout<<"-1";
	return 0;
}