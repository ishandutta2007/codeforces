#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define M 200200

int n, a[M];

int main(){
#ifdef ALG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	long long ans = 0, s = 0;

	for (int i = 0; i < n; ++i)
	if (a[i] == 0)
		++s;

	for (int i = 0; i < n; ++i)
	if (a[i] == 1)
		ans += s;
	else
		--s;

	cout << ans << "\n";

	return 0;
}