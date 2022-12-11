#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#define int long long
using namespace std;

void io() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int tab[(1 << 22)];
int sz[(1 << 22)];

int hDeb, hFin;
vector<int> moves;

void f(int i) {
	if(tab[2 * i] == 0 && tab[2 * i + 1] == 0) {
		tab[i] = 0;
	}
	else {
		if(tab[2 * i] > tab[2 * i + 1]) {
			tab[i] = tab[2 * i];
			f(2 * i);
		}
		else {
			tab[i] = tab[2 * i + 1];
			f(2 * i + 1);
		}
	}
}

bool canDo(int i, int prof) {
	if(tab[2 * i] == 0 && tab[2 * i + 1] == 0) {
		return prof >= hFin;
	}
	else {
		if(tab[2 * i] > tab[2 * i + 1]) {
			return canDo(2 * i, prof + 1);
		}
		else {
			return canDo(2 * i + 1, prof + 1);
		}
	}
}

void clear(int i, int prof) {
	if(prof >= hFin)
		return;

	while(canDo(i, prof)) {
		f(i);
		moves.push_back(i);
	}

	clear(2 * i, prof + 1);
	clear(2 * i + 1, prof + 1);
}

signed main() {
	io();

	int nbTests;
	cin >> nbTests;

	for(int iTest = 0;iTest < nbTests;iTest++) {
		cin >> hDeb >> hFin;

		for(int i = 1;i < (1 << hDeb);i++) {
			cin >> tab[i];
		}

		for(int i = (1 << hDeb);i < 2 * (1 << hDeb);i++) {
			tab[i] = 0;
		}

		clear(1, 0);

		int sum = 0;

		for(int i = 1;i < (1 << hFin);i++) {
			sum += tab[i];
		}

		cout << sum << endl;

		for(int move : moves) {
			cout << move << " ";
		}
		cout << endl;

		moves.clear();
	}
	return 0;
}