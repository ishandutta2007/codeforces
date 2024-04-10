#include <bits/stdc++.h>
#define int long long
#define m_p make_pair
using namespace std;

main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x;
	cin >> n;
	vector <int> a;
	vector <int> b;
	vector <int> c;
	map <int, int> aa;
	map <int, int> bb;
	map <int, int> cc;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
		aa[x]++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> x;
		b.push_back(x);
		bb[x]++;
	}
	for (int i = 0; i < n - 2; i++) {
		cin >> x;
		c.push_back(x);
		cc[x]++;
	}
	for (int i = 0; i < n; i++) {
		if (bb[a[i]] != aa[a[i]]) {
			cout << a[i] << endl;
			break;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (cc[b[i]] != bb[b[i]]) {
			cout << b[i] << endl;
			return 0;
		} 
	}
}