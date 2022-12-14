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
ll a[maxn], k[maxn];
ll n, q;

int bs (ll x){
	int l = 0, r = n + 1;
	while (r - l > 1){
		int mid = (r + l) / 2;
		if (x >= a[mid])
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main (){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int j = 1; j <= q; j++)
		cin >> k[j];
	
	ll tot = 0;
	for (int i = 1; i <= q; i++){
		tot += k[i];
		int m = bs (tot);
		if (m == n){
			tot = 0;
			m = 0;
		}
		cout << n - m << '\n';
	}
}