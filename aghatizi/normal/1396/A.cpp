#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

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

	if(n == 1)
	{
		cout << 1 << " " << n << endl;
		cout << -a[0] << endl;
		cout << 1 << " " << n << endl;
		cout << 0 << endl;
		cout << 1 << " " << n << endl;
		cout << 0 << endl;

		return 0;
	}

	cout << 1 << " " << n << endl;
	for(int i = 0; i < n; i++)
		cout << 1LL * (-a[i]) * n << " ";
	cout << endl;

	cout << 1 << " " << n - 1 << endl;
	for(int i = 0; i < n - 1; i++)
		cout << 1LL * a[i] * (n - 1) << " ";
	cout << endl;

	cout << 2 << " " << n << endl;
	for(int i = 1; i < n - 1; i++)
		cout << 0 << " ";
	cout << 1LL * a[n - 1] * (n - 1) << endl;
}