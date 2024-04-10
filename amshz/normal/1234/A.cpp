# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
int a[xn], ans[xn];

int main(){
	int t, s, n, q;
	cin >> t;
	for (int i=0; i<t; i++){
		s = 0;
		cin >> n;
		for (int j=0; j<n; j++) cin >> q, s += q;
		ans[i] = s/n;
		if (s%n > 0) ans[i]++;
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
}