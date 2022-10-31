#include <bits/stdc++.h>
using namespace std;
int main() {
	string f, t;
	string ip;
	cin >> f;
	cin >> t;
	cin >> ip;
	string res;
	int table[26];
	for (int i = 0; i < 26; i++) {
		table[(int)(f[i] - 'a')] = (int)(t[i] - 'a');
	}

	int k;
	for (int i = 0; i < ip.size(); i++) {
		k = (int)ip[i] - (int)'a';
		if (k >= 0 && k < 26) {
			res.push_back('a' + table[k]);
		}
		else {
			k = (int)ip[i] - (int)'A';
			if (k >= 0 && k < 26) {
				res.push_back('A' + table[k]);
			}
			else {
				res.push_back(ip[i]);
			}
		}
	}
	cout << res << endl;
}