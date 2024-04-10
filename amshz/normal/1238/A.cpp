# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 1e3+10;
bool ans[xn];

int main(){
	int t;
	cin >> t;
	ll x, y;
	for (int i=0; i<t; i++){
		cin >> x >> y;
		if (x-y > 1) ans[i] = 1;
		else ans[i] = 0;
	}
	for (int i=0; i<t; i++){
		if (ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}