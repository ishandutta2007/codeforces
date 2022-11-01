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
		string T;
		cin >> T;
		int c0 = 0, c1 = 0;
		for (int i = 0; i < T.length(); ++i) {
			if (T[i] == '0') {
				++c0;
			}
			else ++c1;
		}
		if (min(c0, c1) == 0) {
			cout << T << "\n";
			continue;
		}
		cout << T[0];
		for (int i = 1; i < T.length(); ++i) {
			if (T[i] == '1' && T[i - 1] == '1')cout << '0';
			if (T[i] == '0' && T[i - 1] == '0')cout << '1';
			cout << T[i];
		}
		cout << "\n";
	}
	return 0;
}