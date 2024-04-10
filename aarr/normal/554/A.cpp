#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N], b[N];
set <string> s;

int main() {
	string t;
	cin >> t;
	for (int i = 0; i <= t.size(); i++) {
		for (char c = 'a'; c <= 'z'; c++) { 
			string p;
			for (int j = 0; j < i; j++) {
				p += t[j];
			}
			p += c;
			for (int j = i; j < t.size(); j++) {
				p += t[j];
			}
			s.insert(p);
		}
	}
	cout << s.size();
	return 0;
}