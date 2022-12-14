#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1000 + 50;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
int a[20], b[30];

int ad (string s){ 
	if (s == "XXXS")
		return 0;
	if (s == "XXS")
		return 1;
	if (s == "XS")
		return 2;
	if (s == "S")
		return 3;
	if (s == "M")
		return 4;
	if (s == "L")
		return 5;
	if (s == "XL")
		return 6;
	if (s == "XXL")
		return 7;
	return 8;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int x = ad (s);
		a[x] ++;
	}
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int x = ad (s);
		b[x] ++;
	}
	ll ans = 0;
	for (int i = 0; i <= 8; i++)
		if (b[i] > a[i])
			ans += b[i] - a[i];
	cout << ans << endl;
}