#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		int flag = 1;
		for(int i = 0; i < n; i++)
		{
			swap(c[i], a[i]);
			if(a[i] == b[i])
				continue;
			swap(c[i], a[i]);
			swap(c[i], b[i]);
			if(a[i] == b[i])
				continue;
			flag = 0;
			break;
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}