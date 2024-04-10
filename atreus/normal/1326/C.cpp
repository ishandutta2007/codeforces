#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const int mod = 998244353;

int p[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	ll ans = 0, num = 1;
	for (int i = n; i >= n-k+1; i--)
		ans += i;
	int last = 0;
	for (int i = 1; i <= n; i++){
		if (p[i] < n-k+1)
			continue;
		if (last != 0){
			int len = i - last;
			num = num * len % mod;
		}
		last = i;
	}
	cout << ans << " " << num << endl;
}