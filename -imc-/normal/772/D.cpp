#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

#define count sjkdhfaljhfl

const int L = 6;
const int L2 = 1 << L;
const int tens[L] = {1, 10, 100, 1000, 10000, 100000};
const int N = 1000000;
int digit[N][L];

const int mod = 1000000007;

long long sum[N], sum2[N], count[N];
long long deg[N];

long long G[N];

int getNext(int index, int mask) {
	for (int i = 0; i < L; ++i) {
		if (mask & (1 << i)) {
			if (digit[index][i] == 9) {
				return -1;
			} else {
				index += tens[i];
			}
		}
	}
	return index;
}

int main(){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < L; ++j) {
			digit[i][j] = i / tens[j] % 10;
		}
	}

	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int x = nxt();
		sum[x] = (sum[x] + x) % mod;
		sum2[x] = (sum2[x] + 1ll * x * x) % mod;
		count[x] += 1;
	}

	deg[0] = 1;
	for (int i = 1; i < N; ++i) {
		deg[i] = deg[i - 1] * 2 % mod;
	}

	for (int index = N - 1; index >= 0; --index) {
		for (int mask = 1; mask < L2; ++mask) {
			int sign = __builtin_parity(mask) ? 1 : -1;
			int new_index = getNext(index, mask);
			if (new_index == -1) {
				continue;
			}
			count[index] += count[new_index] * sign;
			sum[index] += sum[new_index] * sign;
			sum2[index] += sum2[new_index] * sign;
		}
		count[index] %= mod;
		if (count[index] < 0) {
			count[index] += mod;
		}
		sum[index] %= mod;
		if (sum[index] < 0) {
			sum[index] += mod;
		}
		sum2[index] %= mod;
		if (sum2[index] < 0) {
			sum2[index] += mod;
		}
	}

	// cerr << count[121] << " " << count[122] << " " << count[221] << " " << count[222] << "\n";

	for (int index = 0; index < N; ++index) {
		if (count[index] == 0) {
			continue;
		}
		if (count[index] == 1) {
			G[index] = sum2[index];
			continue;
		}

		long long lol = 1ll * sum[index] * sum[index] + sum2[index];
		lol %= mod;
		lol = lol * deg[count[index] - 2] % mod;
		G[index] = lol;
	}

	long long ans = 0;
	for (int index = 0; index < N; ++index) {
		for (int mask = 1; mask < L2; ++mask) {
			int sign = __builtin_parity(mask) ? -1 : 1;
			int new_index = getNext(index, mask);
			if (new_index == -1) {
				continue;
			}
			G[index] += G[new_index] * sign;
		}
		G[index] %= mod;
		if (G[index] < 0) {
			G[index] += mod;
		}

		ans ^= 1ll * index * G[index];
	}

	cout << ans << "\n";

	return 0;
}