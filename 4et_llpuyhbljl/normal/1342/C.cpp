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
		int a, b;
		cin >> a >> b;
		if (b > a)swap(a, b);
		int gc = gcd(a, b);
		long long lc = a * b / gc;
		vector<long long>sp;
		for (int i = 0; i < lc; ++i)if ((i % b) % a != (i % a) % b)sp.push_back(i);
		int q;
		cin >> q;
		vector<long long>Vd;
		while (q--) {
			long long l, r;
			cin >> l >> r;
			long long ans;
			if (r / lc == l / lc) {
				r %= lc;
				l %= lc;
				ans = upper_bound(sp.begin(), sp.end(), r) - lower_bound(sp.begin(), sp.end(), l);
			}
			else {
				long long tl = l % lc;
				long long tr = r % lc;
				ans = upper_bound(sp.begin(), sp.end(), tr) - sp.begin();
				ans += sp.end() - lower_bound(sp.begin(), sp.end(), tl);
				long long tmp = r / lc - l / lc - 1;
				ans += (long long)sp.size() * tmp;
			}
			Vd.push_back(ans);
		}
		for (auto x : Vd)cout << x << " ";
		cout << "\n";
	}
	return 0;
}