#include <bits/stdc++.h>

using namespace std;

int main() {
	pair<string , string> cur;
	cin >> cur.first >> cur.second;
	int  n;
	cin >> n;
	string killed, next;
	cout << cur.first << ' ' << cur.second << endl;	
	for (int i = 0; i < n; ++i) {
		cin >> killed >> next;
		if (cur.first == killed)
			cur.first = next;
		else
			cur.second = next;
		cout << cur.first << ' ' << cur.second << endl;
	}
}