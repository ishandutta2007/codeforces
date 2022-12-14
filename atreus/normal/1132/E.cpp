#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e4 + 10;
const ll inf = 2e12;

ll cnt[10], used[10];

int main(){
	ios_base::sync_with_stdio(false);
	ll w;
	cin >> w;
	ll sum = 0;
	for (int i = 1; i <= 8; i++){
		cin >> cnt[i];
		sum += cnt[i] * i;
	}
	if (sum <= w)
		return cout << sum << endl, 0;
	sum = 0;
	for (int i = 8; i >= 1; i--){
		if (1ll * i * cnt[i] <= w){
			w -= 1ll * i * cnt[i];
			sum += 1ll * i * cnt[i];
			used[i] += cnt[i];
		}
		else{
			ll tmp = w % i;
			sum += (w - tmp);
			used[i] += (w - tmp) / i;
			w = tmp;
		}
	}
	if (w == 0)
		return cout << sum << endl, 0;
	ll x = sum;
	for (int j = 1; j <= 8; j++){
		int q = 5;
		while (used[j] > 0 and q--){
			used[j] --;
			w += j;
			sum -= j;
		}
	}
	bitset<500> bs;
	bs[0] = 1;
	for (int i = 1; i <= 8; i++){
		for (int j = 1; j <= min(cnt[i] - used[i], 500ll); j++)
			bs |= (bs << i);
	}
	for (int k = w; k >= 0; k--)
		if (bs[k] == 1)
			return cout << max(x, sum + k) << endl, 0;
}