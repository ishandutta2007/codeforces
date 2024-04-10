#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld p[25];
ld dp[(1<<20)+10], cnt[(1<<20)+10];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int num = 0;
	for (int i = 0; i < n; i++){
		cin >> p[i];
		num += (p[i] != 0.);
	}
	if (num < k){
		for (int i = 0; i < n; i++)
			cout << (p[i] != 0.0) << " ";
		cout << '\n';
		return 0;
	}
	dp[0] = 1;
	for (int mask = 0; mask < (1<<n); mask++){
		if (__builtin_popcount(mask) > k)
			continue;
		for (int i = 0; i < n; i++){
			if (mask & (1<<i)){
				int sub = mask ^ (1<<i);
				cnt[mask] = cnt[sub] + p[i];
				if (p[i] != 0)
					dp[mask] += p[i] * dp[sub] / (1. - cnt[sub]);
			}
		}
	}
	for (int i = 0; i < n; i++){
		ld answer = 0;
		for (int mask = 0; mask < (1<<n); mask++){
			if (__builtin_popcount(mask) != k)
				continue;
			if (mask & (1 << i))
				answer += dp[mask];
		}
		cout << fixed << setprecision(6) << answer << " ";
	}
	cout << '\n';
}