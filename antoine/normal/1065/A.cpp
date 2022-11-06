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

ll f() {
	ll s, a, b, c;
	cin >> s >> a >> b >> c;

	ll x = s / c;
	return x + (x / a) * b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int t;
	cin >>t;
	while(t--) cout << f() << '\n';


	return 0;
}