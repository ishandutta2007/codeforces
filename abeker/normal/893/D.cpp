#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, D;
int a[MAXN];
ll mx[MAXN];
ll pref[MAXN];

void load() {
	scanf("%d%d", &N, &D);
	for (int i = 1; i <= N; i++) 
		scanf("%d", a + i);
}

int solve() {
	for (int i = 1; i <= N; i++)
		pref[i] = pref[i - 1] + a[i];
	
	for (int i = N; i >= 0; i--)
		mx[i] = i < N ? max(pref[i], mx[i + 1]) : pref[i];
	
	ll curr = 0;
	int sol = 0;
	for (int i = 1; i <= N; i++) {
		if (!a[i] && pref[i] + curr < 0) { 
			ll add = (ll)D - mx[i - 1] - curr;
			if (pref[i] + curr + add < 0)
				return -1;
			curr += add;
			sol++;
		}
		pref[i] += curr;
	}
	
	for (int i = 1; i <= N; i++)
		if (pref[i] > D)
			return -1;
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}