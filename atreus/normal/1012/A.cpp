#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
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
const int maxn = 4e5 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;
ll a[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	int m;
	cin >> m;
	int n = m * 2;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	
	ll ans = (1ll << 62);
	for (int i = 2; i <= m; i++) 
		ans = min (ans, (a[i + m - 1] - a[i]) * (a[n] - a[1]));
	ans = min (ans, (a[m] - a[1]) * (a[n] - a[m + 1]));
	cout << ans << endl;
}