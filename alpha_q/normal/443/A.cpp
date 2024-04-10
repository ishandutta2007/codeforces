#include <bits/stdc++.h>

using namespace std;

string s;

int main (int argc, char const *argv[]) {
//	freopen("input.txt", "r", stdin);	
	
	set <char> x;
	getline(cin, s);
	int l = s.size();

	if (s[1] != '}') for (int i = 1; i < l; i += 3) x.insert(s[i]);

	cout << x.size() << endl;
	return 0;
}