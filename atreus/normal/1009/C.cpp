#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
int c[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ll mnn = (1ll << 60), mxx = -1;
	for (ll i = 1; i <= n; i++) {
		ll k = i * (i - 1) / 2;
		ll x = n - i;
		k += x * (x + 1) / 2;
		mnn = min (mnn, k);
		mxx = max (mxx, k);
	}
	
	ll sum = 0;
	for (int i = 1; i <= m; i++) {
		ll x, d;
		cin >> x >> d;
		if (d <= 0)
			sum += (mnn * d) + n * x;
		else
			sum += (mxx * d) + n * x;
	}
	cout << fixed << setprecision(6) << 1.0 * sum / n << endl;
}