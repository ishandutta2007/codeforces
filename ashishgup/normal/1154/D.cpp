#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, b, a;
int s[N];

int32_t main()
{
	IOS;
	cin >> n >> b >> a;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	int ans = 0;
	int mxa = a;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == 1)
		{
			if(b > 0 && a < mxa)
				b--, a++;
			else if(a > 0)
				a--;
			else if(b > 0)
				b--;
			else
			{
				ans = max(ans, i - 1);
				break;
			}
		}	
		else
		{
			if(a > 0)
				a--;
			else if(b > 0)
				b--;
			else
			{
				ans = max(ans, i - 1);
				break;
			}
		}
		ans = max(ans, i);
	}
	cout << ans;
	return 0;
}