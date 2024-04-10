#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int sz[maxn] , mx[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		sz[i] = k;

		while(k--)
		{
			int x;
			cin >> x;
			mx[i] = max(mx[i] , x);
		}
	}

	int Mx = *max_element(mx , mx + n);

	ll res = 0;
	for(int i = 0; i < n; i++)
		res += 1LL * (Mx - mx[i]) * sz[i];

	cout << res << endl;
}