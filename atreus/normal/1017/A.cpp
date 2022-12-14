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

pii p[maxn];


int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		p[i] = {a + b + c + d, -i};
	}
	sort (p + 1, p + n + 1, greater <pii> ());
	for (int i = 1; i <= n; i++)
		if (p[i].S == -1)
			return cout << i << endl, 0;
}