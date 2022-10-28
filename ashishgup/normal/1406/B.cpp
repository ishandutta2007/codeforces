#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> pos, neg;
		int zero = 0;
		int ans = -2e18;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] > 0)
				pos.push_back(a[i]);
			else if(a[i] < 0)
				neg.push_back(a[i]);
			else
				zero++;
		}
		if(zero > 0)
			ans = max(ans, 0LL);
		sort(pos.rbegin(), pos.rend());
		sort(neg.begin(), neg.end());
		for(int i = 0; i <= (int)pos.size() && i <= 5; i++)
		{
			int j = 5 - i;
			if(j > neg.size())
				continue;
			int cur = 1;
			for(int k = 0; k < i; k++)
				cur *= pos[k];
			for(int k = 0; k < j; k++)
				cur *= neg[k];
			ans = max(ans, cur);
		}
		sort(neg.rbegin(), neg.rend());
		for(int i = 0; i <= (int)pos.size() && i <= 5; i++)
		{
			int j = 5 - i;
			if(j > neg.size())
				continue;
			int cur = 1;
			for(int k = 0; k < i; k++)
				cur *= pos[k];
			for(int k = 0; k < j; k++)
				cur *= neg[k];
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}