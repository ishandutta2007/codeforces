#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll x[100], r[100];

int main(){
	ios_base::sync_with_stdio (false);
	int q;
	cin >> q;
	while (q --){
		ll a, b, m;
		cin >> a >> b >> m;
		if (b == a){
			cout << 1 << " " << a << endl;
			continue;
		}
		if (b == a + 1){
			cout << 2 << " " << a << " " << b << endl;
			continue;
		}
		x[1] = a;
		x[2] = a + 1;
		int i;
		for (i = 3; ; i++){
			x[i] = 2ll * x[i - 1];
			if (x[i] > b){
				i --;
				break;
			}
		}
		if (x[i + 1] == b){
			cout << i + 1 << " ";
			for (int j = 1; j <= i + 1; j++)
				cout << x[j] << " ";
			cout << endl;
			continue;
		}
		ll diff = b - x[i];
		for (int j = 2; j < i; j++){
			r[j] = 1;
			ll z = min(m - 1, diff / (1ll << (i - j - 1)));
			r[j] += z;
			diff -= 1ll * z * (1ll << (i - j - 1));
		}
		r[i] = 1;
		ll z = min(m - 1, diff);
		r[i] += z;
		diff -= z;
		if (diff != 0){
			cout << -1 << endl;
			continue;
		}
		x[1] = a;
		x[2] = a + r[2];
		for (int j = 3; j <= i; j++){
			x[j] = r[j];
			for (int k = j - 1; k >= 1; k--)
				x[j] += x[k];
		}
		cout << i << " ";
		for (int j = 1; j <= i; j++)
			cout << x[j] << " ";
		cout << endl;
	}
}