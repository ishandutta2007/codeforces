#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

vector<int> d[maxn] , posbefore[maxn];

ll a[maxn] , mnSum[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 1; i < maxn; i++)
		for(int j = i; j < maxn; j += i)
			d[j].pb(i);

	int n;
	cin >> n;

	for(int i = 2; i <= n; i += 2)
	{
		cin >> a[i];

		for(auto div : d[a[i]])
		{
			int tmp = a[i] / div;

			if(div <= tmp && (tmp - div) % 2 == 0)
				posbefore[i].pb((tmp - div) / 2);
		}
	}

	fill(mnSum + 1 , mnSum + maxn , 2e18);
	for(int i = 1; i <= n; i += 2)
	{
		bool f = 0;
		for(auto X : posbefore[i + 1])
		{
			ll k = 1LL * X * X;
			if(mnSum[i - 1] < k)
				mnSum[i + 1] = min(mnSum[i + 1] , k + a[i + 1]) , f = 1;
		}

		if(!f)
			return cout << "No" << endl , 0;
	}

	cout << "Yes" << endl;

	for(int i = 1; i <= n; i++)
		cout << (i % 2 == 0? a[i] : mnSum[i + 1] - mnSum[i - 1] - a[i + 1]) << " ";
	cout << endl;
}