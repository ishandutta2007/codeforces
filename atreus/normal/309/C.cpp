#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 3;
const int mod = 1e9 + 7;

int a[maxn], b[40], c[40];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++){
		int x;
		cin >> x;
		b[x] ++;
	}
	sort(a, a + n, greater<int>());
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 30; j >= 0; j--){
			int k = a[i] / (1 << j);
			k = min(k, b[j]);
			a[i] -= k * (1 << j);
			b[j] -= k;
			c[j] += k;
			ans += k;
		}
	}
	ll now = 0;
	for (int i = 30; i >= 0; i--){
		if (c[i] == 0)
			continue;
		int cnt = 0;
		for (int j = i - 1; j >= 0; j--)
			cnt += b[j];
		if (cnt == 0)
			break;
		now = (1 << i);
		c[i] --;
		for (int j = i - 1; j >= 0; j--){
			int k = now / (1 << j);
			k = min(k, b[j]);
			now -= k * (1 << j);
			b[j] -= k;
			c[j] += k;
			ans += k;
		}
		ans --;
		i ++;
	}
	cout << ans << endl;
}