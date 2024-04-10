#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n; cin >> n;
	cout << max(2 * (n/3), 2 * ((n - 1)/3) + 1) << endl;
	return 0;
}