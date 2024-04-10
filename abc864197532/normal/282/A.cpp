#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	int x = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "X++" or s == "++X") x++;
		else x--;
	}
	cout << x;
}