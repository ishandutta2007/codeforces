#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> r;
	int q = 1;
	while(n >= q) {
		r.push_back(q);
		n -= q;
		q++;
	}
	r.back() += n;
	cout << r.size() << "\n";
	for(int b : r)
		cout << b << ' ';
}