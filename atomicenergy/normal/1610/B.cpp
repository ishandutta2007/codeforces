
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



int main()
{
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n ;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		bool ok = true;
		for (int i = 0; i < n-1-i; i++) {
			if (v[i] == v[n - 1 - i]) continue;
			else {
				int ig = v[i];
				int f = i;
				int l = n - 1 - i;
				bool okok = true;
				while (f < l) {
					if (v[f] == ig) {
						f++;
						continue;
					}
					if (v[l] == ig) {
						l--;
						continue;
					}
					if (v[f] == v[l]) {
						f++;
						l--;
						continue;
					}
					okok = false;
					break;
				}
				 ig = v[n-1-i];
				 f = i;
				 l = n - 1 - i;
				bool okokok = true;
				while (f < l) {
					if (v[f] == ig) {
						f++;
						continue;
					}
					if (v[l] == ig) {
						l--;
						continue;
					}
					if (v[f] == v[l]) {
						f++;
						l--;
						continue;
					}
					okokok = false;
					break;
				}
				if (!okok && !okokok) ok = false;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}

}