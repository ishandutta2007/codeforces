#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int b;
	int k;
	
	bool f = false;
	for (int i = 1; i < n; i++) {
		b = a[i] - a[0];
		k = -1;
		f = true;
		//cerr << b << endl;
		for (int j = 1; j < n; j++) {
			
			if ((b*j) == (i * (a[j] - a[0]))) {

			}
			else if(k == -1){
				k = j;
			}
			else if((a[j]-a[k])*i==(j-k)* b){
				
			}
			else {
				f = false;
				break;
			}
		}
		//cerr << k << endl;
		if (k == -1) {
			f = false;
		}
		if (f) break;
	}
	if (!f) {
		reverse(a.begin(), a.end());
		for (int i = 1; i < n; i++) {
			b = a[i] - a[0];
			k = -1;
			f = true;
			//cerr << b << endl;
			for (int j = 1; j < n; j++) {

				if ((b*j) == (i * (a[j] - a[0]))) {

				}
				else if (k == -1) {
					k = j;
				}
				else if ((a[j] - a[k])*i == (j - k)* b) {

				}
				else {
					f = false;
					break;
				}
			}
			//cerr << k << endl;
			if (k == -1) {
				f = false;
			}
			if (f) break;
		}
	}
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}