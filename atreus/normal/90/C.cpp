#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e4 + 100;
ll a[maxn];

int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n % 2 == 0)
		return cout << 0 << endl, 0;
	ll op = m / ((n + 1) / 2);
	op *= k;
	ll minn = 1000 * 1000 * 1000;
	for (int i = 1; i <= n; i += 2)
		minn = min(minn, a[i]);
	cout << min (minn, op) << endl;
}