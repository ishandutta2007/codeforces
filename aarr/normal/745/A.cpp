#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set <string> s;
int main() {
	string t;
	cin >> t;
	for (int i = 0; i < t.size(); i++) {
		string p;
		for (int j = i; j < t.size(); j++) {
			p += t[j];
		}
		for (int j = 0; j < i; j++) {
			p += t[j];
		}
		s.insert(p);
	}
	cout << s.size();
}