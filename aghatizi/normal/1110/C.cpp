#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = (1 << 25) + 20;

int ans[40] = {0 , 1 , 1 , 5 , 1 , 21 , 1 , 85 , 73 , 341 , 89 , 1365 , 1 , 5461 , 4681 , 21845 , 1 , 87381 , 1 , 349525 , 299593 , 1398101 , 178481 , 5592405 , 1082401};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	while(q--)
	{
		int x;
		cin >> x;

		int hb = 31 - __builtin_clz(x);
		if(x == (1 << (hb + 1)) - 1)
			cout << ans[hb] << endl;
		else
			cout << (1 << (hb + 1)) - 1 << endl;
	}
}