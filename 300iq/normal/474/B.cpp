#include <bits/stdc++.h>

using namespace std;

int k[1000010];

int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;	
	int l = 0, r;
	for (int i = 0; i < n; i++) {
		cin >> r;
		for (int j = l + 1; j <= l + r; j++)
			k[j] = i + 1;
		l = l + r;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l;
		cout << k[l] << endl;
	}
}