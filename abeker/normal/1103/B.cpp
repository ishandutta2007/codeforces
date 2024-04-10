#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 30;

bool ask(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	char ans;
	scanf(" %c", &ans);
	return ans == 'x';
}

void finish(int lo, int hi) {
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (ask(lo - 1, mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("! %d\n", ask(hi, lo) ? lo : hi);
	fflush(stdout);
}

void solve() {
	for (int i = 1; i < MAX; i *= 2) 
		if (ask(i, 2 * i)) {
			finish(i, 2 * i);
			return;
		}
}

int main() {
	while (1) {
		string game;
		cin >> game;
		if (game == "end" || game == "mistake")
			return 0;
		solve();
	}
	return 0;
}