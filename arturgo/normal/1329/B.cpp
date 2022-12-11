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

int d, m;
int curPasse = 0;
int derPasse[32];
int dyn[32];

int nb(int bit) {
	if(bit == 0) {
		return 0;
	}

	if(derPasse[bit] == curPasse)
		return dyn[bit];
	derPasse[bit] = curPasse;

	int val = (1 << (bit - 1));

	for(int i = 0;i < bit;i++)
		val = (val + ((1 << (bit - 1)) * nb(i))) % m;

	return (dyn[bit] = val);
}

signed main() {
	io();

	int nbTests;
	cin >> nbTests;

	for(int iTest = 0;iTest < nbTests;iTest++) {
		cin >> d >> m;

		curPasse++;

		int sum = 0;

		int log = 0;
		for(;(1 << log) <= d + 1;log++) {
			sum = (sum + nb(log)) % m;
		}
		log--;

		sum = (sum + (1 + sum) * (d - (1 << log) + 1)) % m;

		cout << sum << endl;
	}
	return 0;
}