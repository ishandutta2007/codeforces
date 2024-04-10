#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			if(a[i][0] == s[0] && a[i][1] == s[1] || a[i][1] == s[0] && a[j][0] == s[1] || a[j][0] == s[0] && a[j][1] == s[1])
				return cout << "YES", 0;
		}
	cout << "NO";
}