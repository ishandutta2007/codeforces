#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, x;
	cin >> n >> x;
	n %= 6;
	vector<int> nw;
	if(n == 0) {
		nw = {0, 1, 2};
	} else if(n == 1) {
		nw = {1, 0, 2};
	} else if(n == 2) {
		nw = {1, 2, 0};
	} else if(n == 3) {
		nw = {2, 1, 0};
	} else if(n == 4) {
		nw = {2, 0, 1};
	} else if(n == 5) {
		nw = {0, 2, 1};
	}
	cout << nw[x];
}