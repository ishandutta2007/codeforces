# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int xn = 1e5+10;

int main(){
	int qq;
	cin >> qq;
	while (qq--){
		ll n, k, a, b;
		cin >> k >> n >> a >> b;
		ll l = 0, r = n+1, mid, m;
		while (l+1 < r){
			mid = (l+r)/2;
			if ((n-mid)*b < k-a*mid) l = mid;
			else r = mid;
		}
		if (k - n*b <= 0){
			cout << -1 << endl;
			continue;
		}
		cout << l << endl;
	}
}