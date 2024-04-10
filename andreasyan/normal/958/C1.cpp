#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
int n;
long long mod;
long long a[N], px[N];

long long check(int x)
{
	long long s1 = px[x];
	long long s2 = px[n] - px[x];
	return s1 % mod + s2 % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> mod;
	int i;
	long long ans = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		px[i] = px[i - 1] + a[i];
	}
	for (i = 1; i < n; i++)
		ans = max(ans, check(i));
	cout << ans << endl;
	return 0;
}