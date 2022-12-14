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
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
ll a[maxn];
vector <pair <ll, ll> > v;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll l, r;
		cin >> l >> r;
		r ++;
		v.PB (MP (l, 0));
		v.PB (MP (r, 1));
	}
	sort (v.begin(), v.end());
	ll cnt = 0, pre = 0;
	for (auto w : v) {
		a[cnt] += w.F - pre;
		pre = w.F;
		if (w.S == 0) 
			cnt ++;
		else
			cnt --;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}