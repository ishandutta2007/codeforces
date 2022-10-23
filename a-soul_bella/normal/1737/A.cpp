#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[1000005],ans[1005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		string s;
		cin >> n >> k >> s;
		for(int i=1;i<=k;i++) ans[i]='a';
		int mx=n/k+'a';
		sort(s.begin(),s.end());
		for(auto t:s)
		{
			for(int i=1;i<=k;i++)
			{
				if(ans[i]==t&&ans[i]!=mx)
				{
					++ans[i];
					break;
				}
			}
		}
		for(int i=1;i<=k;i++)
		{
			cout << (char)ans[i];
		}
		cout << "\n";
	}
	return 0;
}