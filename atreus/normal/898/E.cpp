#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;
const int maxn = 1e6 + 100;
pair <ll, ll> a[maxn];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].S;
		ll p = sqrt(a[i].S);
		ll q = p + 1;
		a[i].F = min(a[i].S - p * p, q * q - a[i].S);
	}
	ll k = 0;
	sort (a, a + n);
	for (int i = 0; i < n / 2; i++){
		k += a[i].F;
	}
	for (int i = n / 2; i < n; i++){
		if (a[i].S == 0)
			k += 2;
		else if (a[i].F == 0)
			k ++;
	}
	cout << k << endl;
}