#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, ans1=0, ans2=0;
vector<int> v[N];
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int num;
			cin>>num;
			v[i].push_back(num);
			if(k%2)
				ans1+=(j<(k+1)/2)?num:0;
			else
				ans1+=(j<=k/2)?num:0;
			if(k%2)
				ans2+=(j>(k+1)/2)?num:0;
			else
				ans2+=(j>k/2)?num:0;
		}
		if(k%2)
			ans.push_back(v[i][k/2]);
	}
	sort(ans.rbegin(), ans.rend());
	for(int i=0;i<ans.size();i++)
	{
		if(i%2)
			ans2+=ans[i];
		else
			ans1+=ans[i];
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}