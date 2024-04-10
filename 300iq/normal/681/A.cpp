#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	srand(time(NULL));
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	int n;
	cin >> n;
	string s;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> s >> a >> b;
		if (a >= 2400 && b > a) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}