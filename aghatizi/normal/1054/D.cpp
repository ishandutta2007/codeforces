#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 2e5 + 20;

int a[maxn] , px[maxn] , t[maxn];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	int nt = (1 << k) - 1;

	vector<int> cmp;
	cmp.pb(0);

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		px[i] = px[i - 1] ^ a[i];

		if(px[i] > (nt ^ px[i]))
			px[i] ^= nt;

		cmp.pb(px[i]);
	}

	sort(cmp.begin() , cmp.end());
	cmp.resize(unique(cmp.begin() , cmp.end()) - cmp.begin());

	for(int i = 0; i <= n; i++)
	{
		int k = lower_bound(cmp.begin() , cmp.end() , px[i]) - cmp.begin();
		t[k]++;
	}

	ll res = 1LL * (n + 1) * n / 2;
	for(int i = 0; i < (int)cmp.size(); i++)
	{
		int A = t[i] / 2 , B = t[i] - (t[i] / 2);

		res -= 1LL * A * (A - 1) / 2 + 1LL * B * (B - 1) / 2;
	}

	cout << res << endl;
}