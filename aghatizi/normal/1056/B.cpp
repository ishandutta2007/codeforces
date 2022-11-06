#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	ll res = 0;
	for(int i = 0; i < m; i++)
		for(int j = i; j < m; j++)
			if(((i * i) + (j * j)) % m == 0)
			{
				int T1 = (n - i) / m + 1 , T2 = (n - j) / m + 1;

				if(n < i)
					T1 = 0;
				if(n < j)
					T2 = 0;

				if(!i)
					T1--;

				if(i == j)
					res += 1LL * T1 * T1;
				else
					res += 1LL * T1 * T2 * 2;
			}

	cout << res << endl;
}