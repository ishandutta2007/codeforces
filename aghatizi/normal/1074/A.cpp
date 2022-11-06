#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int hor[maxn] , x1[maxn] , x2[maxn] , y[maxn];

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> hor[i];

	for(int i = 0; i < m; i++)
	{
		cin >> x1[i] >> x2[i] >> y[i];

		if(x1[i] != 1)
			i-- , m--;
	}

	sort(hor , hor + n);
	sort(x2 , x2 + m);

	int res = 1e9;
	for(int i = 0; i < n; i++)
	{
		int k = lower_bound(x2 , x2 + m , hor[i]) - x2;
		res = min(res , i + m - k);
	}

	int ind = lower_bound(x2 , x2 + m , 1000 * 1000 * 1000) - x2;
	res = min(res , n + m - ind);

	cout << res << endl;
}