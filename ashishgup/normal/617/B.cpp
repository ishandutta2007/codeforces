#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 1;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int prv = -1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1)
		{
			if(prv != -1)
				ans *= (i - prv);
			prv = i;
		}
	}
	if(prv == -1)
		cout << 0;
	else
		cout << ans;
	return 0;
}