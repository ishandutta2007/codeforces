#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int MAXN = (int)1e5 + 40;
const int infint = (ll)1e9;
const ll inf = (ll)1e18;

int main () {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	int k = a + b - c;
	if (n - k > 0 and k >= a and k >= b)
		cout << (n - k) << endl;
	else
		cout << -1 << endl;
}