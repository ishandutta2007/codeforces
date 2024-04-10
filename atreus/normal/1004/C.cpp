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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
bool mark1[maxn], mark2[maxn];
int par[maxn], a[maxn];

int main() {	
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 2; i--) {
		par[i] = par[i + 1];
		if (!mark2[a[i]]) {
			mark2[a[i]] = 1;
			par[i] ++;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (!mark1[a[i]]) {
			mark1[a[i]] = 1;
			ans += par[i + 1];
		}
	}
	cout << ans << endl;
}