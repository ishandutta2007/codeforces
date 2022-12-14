/**
 *    author:  Atreus
 *    created: 11.01.2019 19:17:21      
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxm = 250000 + 100;
const int maxn = 400 + 10;
const ll maxans = 1e18;

int a[maxn];
int s[maxm], f[maxm], c[maxm], r[maxm], per[maxm];

bool check(int idx, ll x){
	ll fuel = x, cnt = 0;
	for (int i = s[idx]; i < f[idx]; i++){
		ll dis = a[i + 1] - a[i];
		if (dis * c[idx] > fuel){
			fuel = x;
			cnt ++;
		}
		if (dis * c[idx] > fuel)
			return 0;
		fuel -= dis * c[idx];
	}
	return cnt <= r[idx];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++){
		cin >> s[i] >> f[i] >> c[i] >> r[i];
		per[i] = i;
	}
	random_shuffle(per + 1, per + m + 1);
	ll v = 0;
	for (int idx = 1; idx <= m; idx++){
		int i = per[idx];
		if (check(i, v) == 1)
			continue;
		ll lo = v, hi = maxans;
		while (hi - lo > 1){
			ll mid = (hi + lo) >> 1;
			if (check(i, mid))
				hi = mid;
			else
				lo = mid;
		}
		v = hi;
	}
	cout << v << endl;
}