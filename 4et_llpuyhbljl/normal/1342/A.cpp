#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
#include<bitset>
using namespace std;
//#define double long long;
int gcd(int i, int j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
typedef long double ld;
#define double long double
const double e = 0.000000000001;
const double pi = 3.1415926535898;
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
const long long INF = 100000000000000;
const int Y = 1000000;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	// freopen("INPUT.TXT", "r", stdin);
	//freopen("OUTPUT.TXT", "w", stdout);
	cout.precision(15);
	int t;
	cin >> t;
	while (t--) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		long long res = abs(x - y) * a;
		long long mm = min(x, y);
		res += mm * min(b, 2 * a);
		cout << res << "\n";
	}
	return 0;
}