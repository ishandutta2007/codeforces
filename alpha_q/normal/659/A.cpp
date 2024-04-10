#include <bits/stdc++.h>

using namespace std;

int main() {	
	//freopen("input.txt", "r", stdin);

	int n, a, b; cin >> n >> a >> b;
	int pos = ((a - 1) + b) % n;
	pos = (pos + n) % n;
	cout << pos + 1 << endl;
    return 0;
}