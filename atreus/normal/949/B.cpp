#include <iostream>

using namespace std;
typedef long long ll;

ll f (ll n, ll pos){
	if (pos % 2 == 1)
		return (pos + 1) / 2;
	if (n == 1)
		return 1;
	pos /= 2;
//	if (pos == n)
//		return f (n / 2, 1) + n / 2;
	if (n % 2 == 1){
		if (pos == 1)
			return f (n / 2, n / 2) + (n + 1) / 2;
		else
			return f (n / 2, pos - 1) + (n + 1) / 2;
	}
	return f (n / 2, pos) + (n + 1) / 2;
}

int main (){
	ll n, q;
	cin >> n >> q;
	for (int i = 1; i <= q; i++){
		ll pos;
		cin >> pos;
		cout << f (n, pos) << endl;
	}
}