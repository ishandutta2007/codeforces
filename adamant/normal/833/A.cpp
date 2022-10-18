#include <bits/stdc++.h>

using namespace std;

vector<int> factorize(int n)
{
	vector<int> res;
	if(n % 2 == 0)
	{
		while(n % 2 == 0)
			n /= 2;
		res.push_back(2);
	}
	for(int i = 3; i * i <= min(1000000, n); i += 2)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
				n /= i;
			res.push_back(i);
		}
	}
	if(n > 1)
		res.push_back(n);
	return res;
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		auto A = factorize(__gcd(a, b));
		for(auto it: A)
		{
			int cnt1 = 0, cnt2 = 0;	
			while(a % it == 0)
			{
				cnt1++;
				a /= it;
			}
			while(b % it == 0)
			{
				cnt2++;
				b /= it;
			}
			if((cnt1 + cnt2) % 3 != 0 || 2 * min(cnt1, cnt2) < max(cnt1, cnt2))
			{
				cout << "No\n";
				goto nxt;
			}
		}
		if(a > 1 || b > 1)
		{
			cout << "No\n";
			goto nxt;
		}
		cout << "Yes\n";
		nxt:;
	}
	return 0;
}