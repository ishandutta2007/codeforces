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

	int T;
	cin >> T;

	while(T--)
	{
		ll a , b;
		cin >> a >> b;

		if(a - b != 1)
		{
			cout << "NO" << endl;
			continue;
		}

		a += b;

		bool f = 1;
		for(ll i = 2; i * i <= a; i++)
			if(a % i == 0)
			{
				f = 0;
				break;
			}

		if(f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}