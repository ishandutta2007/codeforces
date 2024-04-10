#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 1005;

int N, K;
bool bio[MAXN];
bitset <2 * MAXN> dp, nxt;

void load() {
	scanf("%d%d", &N, &K);
	while (K--) {
		int a;
		scanf("%d", &a);
		bio[a] = true;
	}
}

int solve() {
	vector <int> vals;
	for (int i = 0; i < MAXN; i++)
		if (bio[i])
			vals.push_back(i - N);
	
	bool pos = true, neg = true, zero = false;
	for (auto it : vals) {
		pos &= it > 0;
		neg &= it < 0;
		zero |= it == 0;
	}
	
	if (zero)
		return 1;
	
	if (pos || neg)
		return -1;
	
	dp.set(MAXN);
	for (int k = 1; ; k++) {
		nxt.reset();
		for (auto it : vals)
			if (it > 0)
				nxt |= dp << it;
			else
				nxt |= dp >> (-it);
		if (nxt.test(MAXN))
			return k;
		dp |= nxt;
	}
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}