#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
ll n;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		if(n % 2 == 1){
			cout << "2" << endl;
		} else {
			ll x = 1, y = n;
			while(y % 2 == 0)
				y /= 2ll, x *= 2ll;
			x *= 2ll;
			if(y == 1){
				cout << "-1" << endl;
				continue;
			}
			if(n * 2ll / x >= x - 10 && x * (x + 1) / 2 <= n)
				cout << x << endl;
			else
				cout << y << endl;
		}
	}
	return 0;
}