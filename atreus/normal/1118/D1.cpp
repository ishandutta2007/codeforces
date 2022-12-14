/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	ll lo = 0, hi = n + 1;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		memset(b, 0, sizeof b);
		ll tmp = 0;
		for (int i = 0; i < n; i++){
			tmp += max(0, a[i] - b[i % mid]);
			b[i % mid] ++;
		}
		if (tmp >= m)
			hi = mid;
		else
			lo = mid;
	}
	if (hi == n + 1)
		return cout << -1 << endl, 0;
	cout << hi << endl;
}