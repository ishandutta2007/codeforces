#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn] , x[maxn] , t[maxn] , id = 1 , ans[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		t[a[i]]++;

		if(!x[a[i]])
			x[a[i]] = id++;
		ans[i] = x[a[i]];

		if(t[a[i]] == (n - a[i]))
			t[a[i]] = 0 , x[a[i]] = 0;
	}

	for(int i = 0; i < n; i++)
		if(t[i] % (n - i) != 0)
			return cout << "Impossible" << endl , 0;

	cout << "Possible" << endl;
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}