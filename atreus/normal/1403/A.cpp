#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 1){
		cout << 1 << " " << 1 << endl;
		cout << -a[1] << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << " " << n << endl;
	for (int i = 1; i <= n; i++){
		ll x = a[i]%(n-1);
		x = (n-1-x);
		cout << x*n << " ";
		a[i] += x*n;
	}
	cout << endl;
	cout << 1 << " " << n-1 << endl;
	for (int i = 1; i <= n-1; i++){
		cout << -a[i] << " ";
		assert(a[i]%(n-1) == 0);
	}
	cout << endl;
	cout << n << " " << n << endl;
	cout << -a[n] << endl;
}