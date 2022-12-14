#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
map <ll, ll> mp;
map <pair <ll, ll>, ll> mpt;
int main (){
	ll n, a, b;
	cin >> n >> a >> b;
	ll tot = 0;
	for (int i = 1; i <= n; i++){
		ll r, x, y;
		cin >> r >> x >> y;
		y = a * x - y;
		tot += mp[y];
		tot -= mpt[MP(x, y)];
		mp[y] ++;
		mpt[MP(x, y)] ++;
	}
	cout << 2 * tot << endl;
}