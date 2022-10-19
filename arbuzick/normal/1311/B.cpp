#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int i;
	for (i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		int j;
		for (j = 0; j < n; j++) 
			cin >> a[j];		
		vector<int> p(m);
		for (j = 0; j < m; j++)
			cin >> p[j];
		sort(p.begin(), p.end());
		int k;
		for (k = 0; k < n; k++) {
			int ind;
			ind = 0;
			for (j = 0; j < n - 1; j++) {
				if (a[j] > a[j + 1]) {
					while (p[ind] - 1 < j) {
						ind += 1;
						if (ind >= m)
							break;
					}
					if (ind >= m)
						break;
					if (p[ind] - 1 == j) {
						int b;
						b = a[j];
						a[j] = a[j + 1];
						a[j + 1] = b;
					}
				}
				if (ind >= m)
					break;
			}
		}
		vector<int> c(n);
		c = a;
		sort(c.begin(), c.end());
		if (a == c)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}