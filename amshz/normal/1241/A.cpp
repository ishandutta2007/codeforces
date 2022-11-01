# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
int ans[xn];

int main(){
	int t, n;
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n;
		if (n == 2) ans[i] = 2;
		else ans[i] = n%2;
	}
	for (int i=0; i<t; i++) cout << ans[i] << endl;
	return 0;
}