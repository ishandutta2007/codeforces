#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define F first
#define S second
using namespace std;

const long long inf = 2e18, maxn = 1e5 + 100;
long long c[maxn];

int main (){
	memset (c, 63, sizeof c);
	long long n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 1; i <= 30; i++)
		c[i] = min(c[i], 2 * c[i - 1]);
	for (int i = 29; i >= 0; i--)
		c[i] = min(c[i], c[i + 1]);
	long long ans = 0, res = inf;
	for (int i = 30; i >= 0; i--){
		while ((1 << i) <= l){
			ans += c[i];
			l -= (1 << i);
		}
//		cout << res << " -> " << ans << " " << c[i] << endl;
		res = min(res, ans + c[i]);
	}
	res = min(res, ans);
	cout << res << endl;
}