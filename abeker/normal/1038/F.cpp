#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 45;

int N;
int len;
char s[MAXN];
int trans[MAXN][MAXN];
int bits[MAXN];
ll dp[MAXN];

void load() {
	scanf("%d%s", &N, s);
}

bool set_bits(int pos) {
	for (int i = 0; i < len; i++)
		if (bits[(pos + i) % N] == -1)
			bits[(pos + i) % N] = s[i] - '0';
		else if (bits[(pos + i) % N] != s[i] - '0')
			return false;
	return true;
}

int get(int x, int y) {
	memset(bits, -1, sizeof bits);
	
	if (!set_bits(x) || !set_bits(y))
		return -1;
	
	int res = 0;
	for (int i = (x + 1) % N; i != y; i = (i + 1) % N)
		res += bits[i] == -1;
	
	return res;
}

ll calc(int first) {
	dp[first] = 1;
	ll res = 1ll << trans[first][first];
	for (int i = first + 1; i < N; i++) {
		dp[i] = 0;
		for (int j = first; j < i; j++)
			if (trans[j][i] != -1)
				dp[i] -= (1ll << trans[j][i]) * dp[j];
		if (trans[i][first] != -1)
			res += (1ll << trans[i][first]) * dp[i];
	}
	return res;
}

ll solve() {
	len = strlen(s);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			trans[i][j] = get(i, j);
	
	ll sol = 0;
	for (int i = 0; i < N; i++)
		sol += calc(i);
		
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}