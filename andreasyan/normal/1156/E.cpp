#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200005;

int n;
int a[N];

int maxu[N];

long long ans;
void bandt(int l, int r)
{
	if (l == r)
		return;
	int m = (l + r) / 2;

	map<int, int> mp, mp1;

	maxu[m + 1] = 0;
	for (int i = m; i >= l; --i)
	{
		maxu[i] = max(a[i], maxu[i + 1]);
		mp[maxu[i] - a[i]]++;
	}

	int j = m + 1;

	int ymaxu = 0;
	for (int i = m + 1; i <= r; ++i)
	{
		ymaxu = max(ymaxu, a[i]);

		while (j != l && maxu[j - 1] <= ymaxu)
		{
			--j;
			mp[maxu[j] - a[j]]--;
			mp1[a[j]]++;
		}
		ans += mp1[ymaxu - a[i]];
		ans += mp[a[i]];
	}
	bandt(l, m);
	bandt(m + 1, r);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	bandt(1, n);
	cout << ans << endl;
	return 0;
}