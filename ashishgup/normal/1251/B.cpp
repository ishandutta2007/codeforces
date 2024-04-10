#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		int odd = 0, cnt0 = 0, cnt1 = 0;
		for(int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			odd |= (s.size() % 2);
			for(auto &it:s)
			{
				cnt0 += (it == '0');
				cnt1 += (it == '1');
			}
		}
		if(odd || (cnt0 % 2 == 0 && cnt1 % 2 == 0))
			cout << n << endl;
		else
			cout << n - 1 << endl;
	}
	return 0;
}