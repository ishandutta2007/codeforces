#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 5;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		ll l, r, m;
		cin >> l >> r >> m;
		for (int a = l; a <= r; a++){
			int x = m % a;
			int diff = (a - x) % a;
			if (diff <= r-l){
				cout << a << " " << r-diff << " " << r << '\n';
				break;
			}
			diff = x;
			if (diff <= r-l){
				cout << a << " " << r << " " << r-diff << '\n';
				break;
			}
		}
	}
}