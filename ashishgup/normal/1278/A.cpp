#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

string p, h;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> p >> h;
		sort(p.begin(), p.end());
		bool ans = 0;
		int psz = p.size();
		for(int i = 0; i + psz - 1 < h.size(); i++)
		{
			string cur = h.substr(i, psz);
			sort(cur.begin(), cur.end());
			if(p == cur)
			{
				ans = 1;
				break;
			}
		}
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}