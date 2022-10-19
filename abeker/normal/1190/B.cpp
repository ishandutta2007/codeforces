#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN];
map <int, int> cnt;
int distinct;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

void in(int val) {
	if (!cnt[val])
		distinct++;
	cnt[val]++;
}

void out(int val) {
	cnt[val]--;
	if (!cnt[val])
		distinct--;
}

bool solve() {
	for (int i = 0; i < N; i++)
		in(a[i]);
		
	bool ok = false;
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (a[i]) {
			out(a[i]);
			in(a[i] - 1);
			if (distinct == N)
				ok = true;
			out(a[i] - 1);
			in(a[i]);
		}
		sum += a[i];
	}
	
	if (!ok)
		return false;
	
	return (sum - (ll)N * (N - 1) / 2) % 2;
}

int main() {
	load();
	puts(solve() ? "sjfnb" : "cslnb");
	return 0;
}