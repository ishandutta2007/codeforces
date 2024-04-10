#include <iostream>
#include <set>
using namespace std;

set <string> s;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	s.insert(s1);
	s.insert(s2);
	cout << s1 << " " << s2 << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t, p;
		cin >> t >> p;
		s.erase(t);
		s.insert(p);
		for (auto q : s) {
			cout << q << " ";
		}
		cout << endl;
	}
	return 0;
}