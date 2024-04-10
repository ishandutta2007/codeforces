#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int qwq=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			qwq+=x-1;
		}
		if(qwq&1) cout << "errorgorn\n";
		else cout << "maomao90\n";
	}
	return 0;
}