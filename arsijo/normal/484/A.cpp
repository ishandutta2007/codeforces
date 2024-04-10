/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld double
#define MAX 500
#define si short int

ll ans(){
	ll l, r;
	cin >> l >> r;
	if(l == r)
		return l;
	for(ll i = 0; i < 63; i++){
		if((l & (1ll << i)) == 0){
			if(l + (1ll << i) > r)
				return l;
			l += (1ll << i);
		}
	}
	return l;
}

int main() {

	//io;

	int n;
	cin >> n;

	while(n--)
		cout << ans() << "\n";

}