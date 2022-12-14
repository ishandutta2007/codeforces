/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		ll n, a, b;
		cin >> n >> a >> b;
		b = min(b, 2ll * a);
		cout << (n / 2) * b + (n % 2) * a << '\n';
	}
}