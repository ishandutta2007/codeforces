#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e2 + 20;

int a[maxn] , b[maxn] , res[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	int x = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i] , x ^= a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i] , x ^= b[i];

	if(x != 0)
		return cout << "NO" << endl , 0;
	
	cout << "YES" << endl;

	for(int i = 0; i < n - 1; i++)
	{
		res[i][0] = a[i];
		b[0] ^= a[i];
	}

	for(int i = 0; i < m; i++)
		res[n - 1][i] = b[i];

	for(int i = 0; i < n; i++ , cout << endl)
		for(int j = 0; j < m; j++)
			cout << res[i][j] << " ";

	cout << endl;
}