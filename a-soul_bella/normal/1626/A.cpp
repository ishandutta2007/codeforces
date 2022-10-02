#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		for(auto t:s) ++cnt[t];
		for(int i=1;i<200;i++)
		{
			if(cnt[i]==1)
			{
				--cnt[i];
				cout << (char)i;
			}
		}
		for(int i=1;i<200;i++)
		{
			if(cnt[i])
			{
				--cnt[i];
				cout << (char)i;
			}
		}
		for(int i=1;i<200;i++)
		{
			if(cnt[i])
			{
				--cnt[i];
				cout << (char)i;
			}
		}
		cout << "\n";
	}
	return 0;
}