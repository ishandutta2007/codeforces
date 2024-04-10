//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

void solve() {
	int n;
	scanf("%d", &n);
	vector <int> t(n);
	map <int, int> mp;
	for (int &i : t) {
		scanf("%d", &i);
		++mp[abs(i)];
	}
	int odp = 0;
	for (auto i : mp) {
		if (i.first == 0) {
			++odp;
			continue;
		}
		if (i.second > 1) {
			odp += 2;
		}
		else {
			++odp;
		}
	}
	printf("%d\n", odp);
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}