#include <bits/stdc++.h>

using namespace std;

string d1[] = {"0", "8"};
string d2[] = {"16", "24", "32", "40", "48", "56", "64", "72", "80", "88", "96"};
string d3[200];

int main() {
	string s; cin >> s;
	int n = s.size();
	
	int p = 0;
	for (int i = 13; i < 125; i++) {
		int m = 8 * i;
		string num = "";
		while (m) num += (char)('0' + (m % 10)), m /= 10;
		reverse(num.begin(), num.end());
		d3[p++] = num;
	}
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cout << "YES\n";
			cout << 0 << endl;
			return 0;
		}
		if (s[i] == '8') {
			cout << "YES\n";
			cout << 8 << endl;
			return 0;
		}
	}
		
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string num = "";
			num += s[i]; 
			num += s[j];
			for (int k = 0; k < 11; k++)
				if (num == d2[k]) {
					cout << "YES\n";
					cout << num << endl;
					return 0;
				}
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++) {
				string num = "";
				num += s[i];
				num += s[j];
				num += s[k];
				for (int l = 0; l < 112; l++)
					if (num == d3[l]) {
						cout << "YES\n";
						cout << num << endl;
						return 0;
					}
			}
	
	cout << "NO\n";
	return 0;
}