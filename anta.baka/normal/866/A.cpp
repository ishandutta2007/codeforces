#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int A;
	cin >> A;
	if(A == 1) cout << "1 1\n1";
	else cout << 2 * A - 2 << " 2\n2 1";
}