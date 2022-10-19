#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
ll a[MAXN], b[MAXN];
vector <pair <ll, char>> ans;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
	for (int i = 0; i < N; i++)
		scanf("%lld", b + i);
}

void bye() {
	puts("IMPOSSIBLE");
	exit(0);
}

void apply(ll k, char op) {
	ans.push_back({k, op});
}

void flip() {
	reverse(b, b + N);
	apply(1, 'R');
}

int check() {
	int res = -1;
	for (int i = 0; i < 2; i++) {
		bool ok = true;
		for (int j = 0; j < N; j++)
			ok &= a[j] == b[j];
		if (ok)
			res = i;
		reverse(b, b + N);
	}
	return res;
}

void solve() {
	if (N == 1) {
		if (a[0] != b[0])
			bye();
		puts("SMALL\n0");
		return;
	}
	
	while (1) {
		for (int i = 0; i < N; i++)
			if (b[i] <= 0)
				bye();
		int tmp = check();
		if (tmp != -1) {
			if (tmp == 1)
				flip();
			break;
		}
		bool inc = true, dec = true;
		for (int i = 1; i < N; i++) {
			inc &= b[i - 1] < b[i];
			dec &= b[i - 1] > b[i];
		}
		if (!inc && !dec)
			bye();
		if (dec) 
			flip();
		if (N == 2) {
			if (a[0] == b[0] && a[1] <= b[1] && !((b[1] - a[1]) % b[0])) {
				apply((b[1] - a[1]) / b[0], 'P');
				break;
			}
			if (a[1] == b[0] && a[0] <= b[1] && !((b[1] - a[0]) % b[0])) {
				apply((b[1] - a[0]) / b[0], 'P');
				flip();
				break;
			}
			apply(b[1] / b[0], 'P');
			b[1] %= b[0];
		}
		else {
			for (int i = N - 1; i; i--)
				b[i] -= b[i - 1];
			apply(1, 'P');
		}
	}	
	
	ll rev = 0, pref = 0;
	for (auto it : ans)	
		if (it.second == 'P')
			pref += it.first;
		else
			rev += it.first;
	if (pref > 2e5) {
		printf("BIG\n%lld\n", pref);
		return;
	}
	reverse(ans.begin(), ans.end());
	printf("SMALL\n%d\n", rev + pref);
	for (auto it : ans)
		while (it.first--)
			printf("%c", it.second);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}