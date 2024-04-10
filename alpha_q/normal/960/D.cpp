#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int L = 63;

int q;
ll shift[L], mod[L];

int level (ll x) {
	int ret = 0;
	while ((1LL << ret) <= x) {
		++ret;
	}
	return ret - 1;
}

ll valToPos (ll x) {
	int l = level(x);
	ll pos = mod[l] + (x + shift[l]) % mod[l];
	return pos;
}

ll posToVal (ll x) {
	int l = level(x);
	ll val = mod[l] + (x + mod[l] - shift[l]) % mod[l];
	return val;
}

int main() {
	mod[0] = 1;
	for (int i = 1; i < L; ++i) {
		mod[i] = mod[i - 1] << 1LL;
	}
  cin >> q;
  while (q--) {
  	int cmd;
  	scanf("%d", &cmd);
  	ll x, k;
  	if (cmd == 1) {
  		scanf("%lld %lld", &x, &k);
  		int l = level(x);
  		k %= mod[l];
  		if (k < 0) k += mod[l];
  		shift[l] += k;
  		if (shift[l] >= mod[l]) shift[l] -= mod[l];
  	} else if (cmd == 2) {
  		scanf("%lld %lld", &x, &k);
  		int l = level(x);
  		k %= mod[l];
  		if (k < 0) k += mod[l];
  		for (int i = l; i < L; ++i) {
  			ll add = k % mod[i];
  			shift[i] += add;
	  		if (shift[i] >= mod[i]) shift[i] -= mod[i];
  			k <<= 1LL;
  			if (k >= mod[L - 1]) k -= mod[L - 1];
  		}
  	} else {
  		scanf("%lld", &x);
  		ll at = valToPos(x);
  		while (at > 1) {
  			printf("%lld ", posToVal(at));
  			at >>= 1;
  		}
  		puts("1");
  	}
  }
  return 0;
}