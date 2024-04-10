#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 1000 + 10;
const int mod = 1e6 + 7;
const int base = 31;

int cntdig(ll x){
	int ret = 0;
	while (x){
		x -= x & -x;
		ret ++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, p;
	cin >> n >> p;
	for (int i = 1; i <= 100; i++){
		n -= p;
		if (n < i)
			return cout << -1 << endl, 0;
		if (cntdig(n) <= i)
			return cout << i << endl, 0;
	}
	cout << -1 << endl;
}