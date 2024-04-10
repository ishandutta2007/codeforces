#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	map<int, int> m;
	for(int i = 2; i * i <= n; i++)
	{
		int cnt = 0;
		while(n % i == 0)
		{
			n /= i;
			cnt++;
		}
		if(cnt > 0)
			m[i] = cnt;
	}
	if(n > 1)
		m[n]++;
	if(m.size() > 1)
		cout << 1;
	else
		cout << m.begin() -> first;
	return 0;
}