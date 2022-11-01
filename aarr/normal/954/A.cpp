#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int D = 86400;
bool b[105];

int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = s.size();
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1] && !b[i - 1]) {
			b[i] = b[i - 1] = true;
			ans--;
		}
	}
	cout << ans;
}