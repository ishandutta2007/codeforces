#include <iostream>
#include <vector>
using namespace std;

vector <int> ans;
int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	s.push_back('W');
	int x = 0, y = 0;
	for (int i = 0; i <= n; i++) {
		if (s[i] == 'W' && i > 0 && s[i - 1] == 'B') {
			ans.push_back(x);
			x = 0;
		}
		x++;
		if (s[i] == 'W')
			x = 0;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}