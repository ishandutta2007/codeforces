#include <bits/stdc++.h>

using namespace std;


vector<int> prefix_function (vector <int> s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}


int main() {
	int n;
	cin >> n;
	vector <int> a;
	vector <int> b;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0)
			a.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0)
			b.push_back(x);
	}
	if (b.size() != a.size()) {
		cout << "NO" << endl;
		return 0;
	}
	vector <int> s;
	for (int i = 0; i < b.size(); i++)
		s.push_back(b[i]);
	s.push_back(-1);
	for (int i = 0; i < a.size(); i++)
		s.push_back(a[i]);
	for (int i = 0; i < a.size(); i++)
		s.push_back(a[i]);
	vector <int> pi = prefix_function(s);
	for (int i = b.size(); i < s.size(); i++) {
		if (pi[i] == b.size()) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;

}