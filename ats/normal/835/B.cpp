#include <bits/stdc++.h>
using namespace std;
int main() {
	int k;
	cin >> k;
	vector<int> n;
	string s;
	cin >> s;
	int p;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		p = (int)(s[i] - '0');
		n.push_back(p); 
		sum += p;
	}
	sort(n.begin(), n.end());
	int res = 0;
	for (int i = 0; i < n.size(); i++) {
		if (k <= sum) {
			break;
		}
		res++;
		sum += 9 - n[i];
	}
	cout << res << endl;
}