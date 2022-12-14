#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 3;
const int mod = 1e6 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, m, t;
	cin >> n >> k >> m >> t;
	while (t --){
		int type, pos;
		cin >> type >> pos;
		if (type == 0){
			if (k <= pos)
				n = pos;
			else
				n -= pos, k -= pos;
		}
		else{
			if (pos <= k)
				k ++;
			n ++;
		}
		cout << n << " " << k << '\n';
	}
}