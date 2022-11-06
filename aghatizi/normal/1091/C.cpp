#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> div;
	for(int i = 1; i * i <= n; i++)
		if(n % i == 0)
		{
			div.pb(i);
			if(i * i != n)
				div.pb(n / i);
		}

	sort(div.begin() , div.end());
	vector<ll> ans;

	for(auto x : div)
	{
		ll tmp = n / x;
		tmp += 1LL * x * (n / x) * (n / x - 1) / 2;

		ans.pb(tmp);
	}

	sort(ans.begin() , ans.end());
	ans.resize(unique(ans.begin() , ans.end()) - ans.begin());

	for(auto x : ans)
		cout << x << " ";
	cout << endl;
}

// 0 + x + ... +