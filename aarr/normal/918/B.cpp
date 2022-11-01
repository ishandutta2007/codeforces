#include <iostream>
#include <map>
using namespace std;

map <string, string> mp;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s >> t;
		mp[t] = s;
	//	cout << t << " " << mp[t] << endl;
	}
	for (int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		t.pop_back();
		cout << s << " " << t << "; #" << mp[t] << endl;
	}
	return 0;
}