//============================================================================
// Name        : P3.cpp
// Author      : Antoine
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m;
	cin >> n >> m;

	if(n == 1 || m == 0) {
		cout << n << ' ' << n << '\n';
		return 0;
	}

	cout << max(0LL, n - 2*m) << ' ';

	ll x = 0;
	while(x*(x-1)/2 < m) ++x;

	assert(x <= n);
	cout << n - x << '\n';



	return 0;
}