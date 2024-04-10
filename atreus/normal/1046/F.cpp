#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;

int a[maxn];

int main () {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int x, f;
	cin >> x >> f;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x)
			continue;
		int k = a[i] / (x + f);
		int l = a[i] % (x + f);
		if (l > x)
			k ++;
		ans += k * f;
	}
	cout << ans << endl;
}