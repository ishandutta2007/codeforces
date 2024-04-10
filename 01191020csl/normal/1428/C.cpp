#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int top = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'A' || !top) ++top;
			else --top;
		cout << top << endl;
	}
}