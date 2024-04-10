# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

# define push_back pb;

const int xn = 1e3+10;

ll a, b, c, d, e, cnt, flag, x, y, z, t, ans;

int main(){
	int q;
	cin >> q;
	while (q--){
		cin >> x;
		t = 0;
		ans = 0;
		while (x%5 == 0) t++, x /= 5;
		for (int i=0; i<t; i++) x *= 4;
		ans += t;
		t = 0;
		while (x%3 == 0) t++, x /= 3;
		for (int i=0; i<t; i++) x *= 2;
		ans += t;
		while (x%2 == 0) x /= 2, ans++;
		if (x == 1){
			cout << ans << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}