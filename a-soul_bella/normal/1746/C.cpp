#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int inf=1e18;
int a[1000005],n,c1[1000005],b[1000005];
priority_queue<pair<int,int> > q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=a[i-1]) b[i]=0;
			else b[i]=a[i-1]-a[i];
			q.push({b[i],i});
		}
		vector<int> ans;
		for(int i=n;i>=1;i--)
		{
			pair<int,int> x=q.top();
			q.pop();
			x.first-=i;
			ans.push_back(x.second);
			q.push(x);
		}
		reverse(ans.begin(),ans.end());
		for(auto t:ans) cout << t << " ";
		cout << "\n";
	}
	return 0;
}