#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> p(n);
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		int f = 1;
		for(int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (p[i][j] == '1') 
					if (i != n - 1 && j != n - 1 && p[i + 1][j] == '0' && p[i][j + 1] == '0') 
						f = 0;
		if (f)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}