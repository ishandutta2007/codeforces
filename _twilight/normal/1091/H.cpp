#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

template <typename T>
void pfill(T* pst, const T* ped, T val) {
	for ( ; pst != ped; *(pst++) = val);
}

const int N = 200001;

class Euler {
	public:
		int f[N];
		vector<int> prime;

		Euler() {
			pfill(f, f + N + 1, 0);
			for (int i = 2; i < N; i++) {
				if (!f[i])
					prime.push_back(i), f[i] = 1;
				for (int j = 0, x; j < (signed) prime.size() && (x = prime[j] * i) < N; j++) {
					f[x] = f[i] + 1;
					if (!(i % prime[j]))
						break;
				}
			}
		}

		void init(bitset<N>& _deci) {
			_deci.set();
			for (int i = 2; i < N; i++)
				if (f[i] <= 2) {
					_deci.reset(i);
//					cerr << i << '\n';
				}
		}		
} Euler;

int n, __;
int SG[N];
bitset<N> _deci;
bitset<N> candidate;	// 0: no 1: yes

int main() {
	Euler.init(_deci);
	scanf("%d%d", &n, &__);
	_deci.set(__);
	pfill(SG, SG + N, -1);
	for (int sg = 0; sg <= N; sg++) {
		candidate.set();
		boolean find = false;
		for (int cur = 0; cur < N; cur++) {
			if (SG[cur] == -1 && candidate.test(cur)) {
				SG[cur] = sg;
				candidate &= _deci << cur;
				find = true;
			}
		}
		if (!find) {
			break;
		}
	}

	int ans = 0;
	for (int i = 1, x, y, z; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		ans ^= SG[y - x - 1];
		ans ^= SG[z - y - 1];
	}
	if (ans) {
		printf("Alice\nBob\n");
	} else {
		printf("Bob\nAlice\n");
	}
	return 0; 
}