#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e5 + 100;

int main(){
	ll k, d, t;
	cin >> k >> d >> t;
	if (k % d == 0)
		d = k;
	else
		d = k - (k % d) + d;
	ll timezone = d + k;
	t *= 2;
	long double ans = d * (t / timezone);
	t %= timezone;
	if (t <= 2 * k)
		return cout << fixed << setprecision(4) << 1.0 * t / 2 + ans << endl, 0;
	ans += k;
	t -= 2 * k;
	ans += t;
	cout << fixed << setprecision(4) << 1.0 * ans << endl;

}