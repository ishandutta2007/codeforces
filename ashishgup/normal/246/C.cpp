#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int n, k;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	set<int> have;
	while(k > 0)
	{
		shuffle(a + 1, a + n + 1, rng);
		for(int i = 1; i <= n && k > 0; i++)
		{
			int sum = 0;
			for(int j = i; j <= n && k > 0; j++)
			{
				sum += a[j];
				if(have.find(sum) == have.end())
				{
					k--;
					cout << j - i + 1 << " ";
					for(int k = i; k <= j; k++)
						cout << a[k] << " ";
					cout << endl;
					have.insert(sum);
				}
			}
		}
	}
	return 0;
}