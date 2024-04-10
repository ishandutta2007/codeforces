// CPP program to convert infix to prefix
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, s;
	cin >> n >> s;
	cout << (s+n-1)/n;

	return 0;
}