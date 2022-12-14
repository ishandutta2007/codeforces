#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
const int mod = 998244353;

int n;

int ask(int x){
	if (x == 0 or x == n+1)
		return mod;
	cout << "? " << x << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	int lo = 0, hi = n+1;
	while (hi - lo > 3){
		int mid = (lo+hi)>>1;
		if (ask(mid) < ask(mid+1))
			hi = mid+1;
		else
			lo = mid;
	}
	if (hi-lo == 2)
		cout << "! " << lo+1 << endl;
	else if (ask(lo+1) < ask(lo+2))
		cout << "! " << lo+1 << endl;
	else
		cout << "! " << lo+2 << endl;
}