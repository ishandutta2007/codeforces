//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

int ask(int x) {
	cout << "? " << x << endl;
	int y;
	cin >> y;
	return y;
}

void solve() {
	int n;
	cin >> n;
	vector <int> t(n + 1), p(n + 1);
	ask(1);
	int k = 0;
	for (int i = 1; i <= n; ++i) {
		if (t[i]) {
			continue;
		}
		if (k == n - 1) {
			break;
		}
		int x = ask(i);
		while (!t[x]) {
			t[x] = ask(i);
			++k;
			if (k == n - 1) {
				break;
			}
			x = t[x];
		}
	}
	k = 0;
	for (int i = 1; i <= n; ++i) {
		p[t[i]] = 1;
		if (!t[i]) {
			k = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!p[i]) {
			t[k] = i;
		}
	}
	cout << "!";
	for (int i = 1; i <= n; ++i) {
		cout << " " << t[i];
	}
	cout << endl;
}

int main() {
	int q=1;
	cin >> q;
	while(q--) {
		solve();
	}
	return 0;
}