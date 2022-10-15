#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


const int MAXN = 1000007;

int n;
int a[MAXN]; 
int f[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//for (int i = 0; i < n; i++)
		//a[i + n] = a[i];


	//for (int i = 0; i < n; i++)
	//{
		//f[0] = 0;
		//for (int j = 1; j < n; j++)
		//{
			//f[j] = n + 1;
			//for (int k = max(0, j - a[i + j]); k < j; k++)
				//f[j] = min(f[j], f[k]);
			//f[j]++;
		//}
		//ans += f[n - 1];
		//cout << f[n - 1] << " ";
	//}
	//cout << endl;
	//cout << ans << endl;
	
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		a[i + n] = a[i];

	for (int i = 0; i < n; i++)
	{
		int res = 1;
		for (int j = i, k = i + a[i]; k < i + n - 1; )
		{
			int f = 0;
			while (j <= k)
			{
				f = max(f, a[j] + j);
				j++;
			}
			k = f;
			res++;
		}
		ans += res;
	}
	cout << ans << endl;
	return 0;
}