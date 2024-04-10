#include <iostream>
#include <vector>
using namespace std;

const int N = 50 * 1000 + 4;

vector <int> v[30];
vector <int> u[30];
int a[30];
int main() {
	int n, m;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		v[c - 'a'].push_back(i + 1);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int ans = 0;
		string t;
		cin >> t;
		for (int j = 0; j < 27; j++) {
			u[j].clear();
			a[j] = 0;
		}
		for (int j = 0; j < t.size(); j++) {
			int x = t[j] - 'a';
			ans = max(ans, v[x][a[x]]);
			a[x]++;
		}
		cout << ans << endl;
	}
	return 0;
}