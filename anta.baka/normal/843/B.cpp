#include <bits/stdc++.h>

using namespace std;

int n, pos, hval, x;
int val, nxt;

void ask(int i) {
	cout << '?' << ' ' << i << endl;
	cin >> val >> nxt;
}

void fin(int ans) {
	cout << '!' << ' ' << ans << endl;
	exit(0);
}

int main() {
	srand(time(NULL));
	cin >> n >> pos >> x;
	ask(pos);
	if(val >= x) fin(val);
	pos = nxt;
	hval = val;
	for(int i = 0; i < 999; i++) {
		ask(1LL * rand() * rand() % n + 1);
		if(val < x) {
			if(nxt == -1) fin(-1);
			if(hval < val) pos = nxt, hval = val;
		}
	}
	for(int i = 0; i < 999; i++) {
		ask(pos);
		if(val >= x) fin(val);
		pos = nxt;
		if(pos == -1) fin(-1);
	}
}