#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	int n, b, d;
	cin >> n >> b >> d;
	
	int c = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if(x > b)
		{
			continue;
		}
		c += x;
		if(c > d)
		{
			++ans;
			c = 0;
		}
	}
	cout << ans << endl;
	return 0;
}