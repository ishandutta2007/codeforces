#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
ll a[maxn];

int main (){
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll maxp = -(1ll << 63);
	ll maxq = maxp, maxr = maxp;
	for (int i = 1; i <= n; i++){
		maxp = max (maxp, a[i] * p);
		maxq = max (maxq, maxp + a[i] * q);
		maxr = max (maxr, maxq + a[i] * r);
	}
	cout << maxr << endl;
}