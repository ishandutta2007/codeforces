#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int mask = 0; mask < (1 << n); mask++)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
			sum += (bit(mask , i)? 1 : -1) * a[i];

		sum %= 360;
		if(sum == 0)
			return cout << "YES" << endl , 0;
	}

	cout << "NO" << endl;
}