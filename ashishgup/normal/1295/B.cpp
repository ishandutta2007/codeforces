#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, x;
string s;
int pref[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x >> s;
		bool flag = 0;
		for(int i = 0; i < n; i++)
		{
			pref[i + 1] = pref[i];
			if(s[i] == '0')
				pref[i + 1]++;
			else
				pref[i + 1]--;
			flag |= (pref[i + 1] == x);
		}
		flag |= (x == 0);
		if(pref[n] == 0)
		{
			if(flag)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			int ans = (x == 0);
			int tot = pref[n];
			for(int i = 0; i < n; i++)
			{
				if((x - pref[i + 1]) % tot == 0 && ((x - pref[i + 1]) * (tot)) >= 0)
					ans++;
			}	
			cout << ans << endl;
		}
	}
	return 0;
}