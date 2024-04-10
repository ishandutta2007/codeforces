#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 4e5 + 5;
const int SQRT = 200;

int N;
char s[MAXN];
int pref[MAXN];
int mini[MAXN], maks[MAXN];

void load() {
	scanf("%s", s + 1);
}

ll get_slopes(int slope) {
	ll res = 0;
	unordered_map <ll, int> cnt;
	for (int i = 0; i <= N; i++)
		res += cnt[i - (ll)slope * pref[i]]++;
	return res;
}

ll solve() {
	N = strlen(s + 1);
	for (int i = 0; i <= N; i++)
		mini[i] = N + 1;
	for (int i = 0; i <= N; i++) {
		if (i)
			pref[i] = pref[i - 1] + (s[i] - '0');
		mini[pref[i]] = min(mini[pref[i]], i);
		maks[pref[i]] = max(maks[pref[i]], i);
	}
	
	ll sol = 0;
	for (int i = 1; i <= SQRT; i++)
		sol += get_slopes(i);
	
	int limit = N / SQRT;
	for (int i = 0; i <= N; i++) 
		for (int j = 1; j <= limit; j++)
			sol += max((maks[pref[i] + j] - i) / j - max(mini[pref[i] + j] - i - 1, j * SQRT) / j, 0);
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}