#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int ile1=0, ile2=0, ile3=0;
	for(int i=0; i<s.size(); ++i) {
		if(s[i]=='1') ++ile1;
		if(s[i]=='2') ++ile2;
		if(s[i]=='3') ++ile3;
	}
	if(ile1>0) {
		cout << "1";
		--ile1;
	} else if(ile2>0) {
		cout << "2";
		--ile2;
	} else {
		cout << "3";
		--ile3;
	}
	for(int i=0; i<ile1; ++i) {
		cout << "+1";
	}
	for(int i=0; i<ile2; ++i) {
		cout << "+2";
	}
	for(int i=0; i<ile3; ++i) {
		cout << "+3";
	}
	cout << '\n';
}