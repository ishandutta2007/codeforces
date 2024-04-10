# include <bits/stdc++.h>

using namespace std;

const int xt = 1e4;
const int xn = 2e5;
long long a[xn];
long long ans[xt];

int main(){
	int t;
	long long r, n, mx;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n;
		r = 0;
		//mx = a[n-1];
		for (int j=0; j<n; j++) cin >> a[j];
		mx = a[n-1];
		for (int j=n-1; j>=0; j--){
			if (a[j] > mx) r += 1;
			else if (a[j] < mx) mx = a[j];
		}
		ans[i] = r;
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
}