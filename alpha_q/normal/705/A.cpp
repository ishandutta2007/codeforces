#include <bits/stdc++.h>

using namespace std;

int main (int argc, char const *argv[]) {
	int n; cin >> n;
	string s = "";
	for (int i = 1; i <= n; ++i) {
		if (i & 1) s += "I hate ";
		else s += "I love ";
		if (i == n) s += "it\n";
		else s += "that ";
	}
	cout << s;
	return 0;
}