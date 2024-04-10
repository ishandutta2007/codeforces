#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> pr = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
		vector<int> b = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
		int color = 0;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		vector<int> c(n);
		for (int i = 0; i < n; ++i) 
			for(int j = 0; j < pr.size(); ++j)
				if (a[i] % pr[j] == 0) {
					if (b[j] == -1) {
						color += 1;
						b[j] = color;
					}
					c[i] = b[j];
					break;
				}
		cout << color << endl;
		for (int i = 0; i < n; ++i)
			cout << c[i] << ' ';
		cout << endl;
	}
	return 0;
}