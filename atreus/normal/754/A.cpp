#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
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
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	ll n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum != 0) {
		cout << "YES" << endl << 1 << endl << 1 << " " << n << endl;
		return 0;
	}
	sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum != 0) {
			cout << "YES" << endl << 2 << endl << 1 << " " << i << endl << i + 1 << " " << n << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}