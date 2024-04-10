#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

int a[maxn], grp[maxn];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, p;
		cin >> n >> p;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (p == 1){
			cout << (n & 1) << '\n';
			continue;
		}
		sort(a, a + n);
		ll diff = 0, pre = a[n-1];
		for (int i = n-1; i >= 0; i--){ // real diffrence is diff * p^pre
			bool found = 0;
			while (pre > a[i]){
				if (diff == 0)
					pre = a[i] + 1;
				diff *= p;
				pre --;
				if (diff >= n){
					for (int j = 0; j <= i; j++)
						grp[j] = 1;
					found = 1;
					break;
				}
			}
			if (found)
				break;
			if (diff == 0){
				grp[i] = 0;
				diff += 1;
			}
			else{
				grp[i] = 1;
				diff --;
			}
		}
		ll answer = 0;
		for (int i = 0; i < n; i++)
			if (grp[i] == 0)
				answer = (answer + power(p, a[i])) % mod;
			else
				answer = (answer - power(p, a[i]) + mod) % mod;
		cout << answer << '\n';
	}
}