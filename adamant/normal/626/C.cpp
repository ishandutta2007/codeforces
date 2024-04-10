#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42;
int used[maxn];

int main()
{
	#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int i;
	int d2 = 0, d3 = 0, d6 = 0;
	for(i = 1; ; i++)
	{
		d2 += i % 2 == 0;
		d3 += i % 3 == 0;
		d6 += i % 6 == 0;
		d2 -= i % 6 == 0;
		d3 -= i % 6 == 0;
		if(d6 >= max(0, n - d2) + max(0, m - d3))
			break;
	}
	cout << i << "\n";
	return 0;
}