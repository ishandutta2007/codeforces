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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 4e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 317;

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	string fi, se;
	cin >> fi >> se;
	ll A1 = 0, A2 = 0, B1 = 0, B2 = 0;
	for (int i = 0; i < n; i++) {
		if (se[i] == '1') {
			if (fi[i] == '1')
				A1 ++;
			else
				A2 ++;
		}
		else {
			if (fi[i] == '1')
				B1 ++;
			else
				B2 ++;
		}
	}
	ll ans = (A1 * B2 + A2 * B1 + B1 * B2);
	cout << ans << endl;
}