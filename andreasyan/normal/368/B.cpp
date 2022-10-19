#include <iostream>
#include <set>
using namespace std;

int n, m, k, a[100005], pr[100005];
set<int> se;
int main()
{
	int i, j, x;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = n; i >=1; i--)
	{
		if (se.find(a[i]) == se.end())
		{
			k++;
			se.insert(a[i]);
		}
		pr[i] = k;
	}
	for (i = 0; i < m; i++)
	{
		cin >> x;
		cout << pr[x] << endl;
	}
	return 0;
}