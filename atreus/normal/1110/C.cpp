/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int ans[30];

int main(){
	ios_base::sync_with_stdio(false);
	ans[25] = 1082401;
	ans[24] = 5592405;
	ans[23] = 178481;
	ans[22] = 1398101;
	for (int i = 2; i <= 21; i++){
		int x = (1 << i) - 1;
		for (int j = 1; j < x; j++){
			ans[i] = max(ans[i], gcd((x ^ j), (x & j)));
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int x;
		cin >> x;
		int y = x + 1;
		int bits = 0;
		while (x){
			x /= 2;
			bits ++;
		}
		if ((y & -y) == y)
			cout << ans[bits] << '\n';
		else
			cout << (1 << bits) - 1 << '\n';
	}
}