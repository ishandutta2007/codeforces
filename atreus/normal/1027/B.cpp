#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;

int main () {
	ios_base::sync_with_stdio (false);
	ll n, q;
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		ll x, y;
		cin >> x >> y;
		if ((x + y) % 2 == 0) {
			ll k = (x - 1) / 2;
			k *= n;
			if (x % 2 == 0) {
				k += (n + 1) / 2;
			}
			k += (y - 1) / 2;
			k ++;
			cout << k << endl;
		}
		else {
			ll k = (x - 1) / 2;
			k *= n;
			k += (n * n + 1) / 2;
			if (x % 2 == 0)
				k += n / 2;
			k += (y - 1) / 2;
			k ++;
			cout << k << endl;
		}
	}
}