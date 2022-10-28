#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int a[N], f[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<int> ans;
	for(int i=n;i>=1;i--)
	{
		if(f[a[i]]==0)
			ans.push_back(a[i]);
		f[a[i]]++;
	}
	reverse(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}