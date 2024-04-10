#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifdef __linux__
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	cout << (n != 2 && n % 2 == 0 ? "YES" : "NO") << endl; 
}