#include <iostream>
#include <map>
using namespace std;

map <pair <char, char>, int> mp;

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i < n; i++) {
		mp[{s[i - 1], s[i]}]++;
	}
	pair <char, char> c;
	int maxi = 0;
	for (auto p : mp) {
	//	cout << p.first.first << p.first.second << " " << p.second << endl;
		if (p.second > maxi) {
			c = p.first;
			maxi = p.second;
		}
	}
	cout << c.first << c.second;
	return 0;
}