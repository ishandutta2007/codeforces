#include <bits/stdc++.h>
using namespace std;

map <string, string> type;

int main() {
	type["great!"] = "normal";
	type["don't think so"] = "normal";
	type["don't touch me!"] = "normal";
	type["not bad"] = "normal";
	type["cool"] = "normal";
	type["don't even"] = "grumpy";
	type["are you serious?"] = "grumpy";
	type["go die in a hole"] = "grumpy";
	type["worse"] = "grumpy";
	type["terrible"] = "grumpy";
	type["no way"] = "grumpy";
	
	for (int i = 0; i < 4; i++) {
		printf("%d\n", i);
		fflush(stdout);
		string s;
		getline(cin, s);
		string ans = type[s];
		if (!ans.empty()) {
			cout << ans << endl;
			fflush(stdout);
			return 0;
		}
	}
	
	puts("normal");
	
	return 0;
}