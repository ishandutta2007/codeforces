#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int x[N], y[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int mxx = 1e5, mnx = -1e5, mxy = 1e5, mny = -1e5;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i] >> y[i];
			for(int j = 1; j <= 4; j++)
			{
				int k;
				cin >> k;
				if(!k)
				{
					if(j == 1)
						mnx = max(mnx, x[i]);
					else if(j == 2)
						mxy = min(mxy, y[i]);
					else if(j == 3)
						mxx = min(mxx, x[i]);
					else
						mny = max(mny, y[i]);
				}
			}
		}
		if(mnx > mxx || mny > mxy)
			cout << 0 << endl;
		else
			cout << 1 << " " << mnx << " " << mny << endl;
	}
	return 0;
}