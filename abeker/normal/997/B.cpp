#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
map <int, int> add[50];

void load() {
	scanf("%d", &N);
}

ll solve() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 49; j++)
			if (i + j <= N) {
				int val = 4 * i + 9 * j;
				int rem = val % 49;
				add[rem][val / 49]++;
				add[rem][val / 49 + N - i - j + 1]--;
			}
	
	ll sol = 0;
	for (int i = 0; i < 49; i++) {
		int pref = 0, lst = -1;
		for (auto it : add[i]) {
			pref += it.second;
			if (!pref) {
				if (lst != -1)
					sol += it.first - lst;
				lst = -1;
			}
			else if (lst == -1)
				lst = it.first;
		}
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}