#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int len;
	cin >> len;
	string s;
	cin >> s;
	for (int i = 0; i < len; ++i) {
		int max, ind;
		max = 0;
		ind = -1;
		for (int j = 0; j < s.size(); ++j) {
			if (int(s[j] - 'a') > max){
				if (j != 0 && j != s.size() - 1) {
					if (int(s[j - 1] - 'a') + 1 == int(s[j] - 'a') || int(s[j + 1] - 'a') + 1 == int(s[j] - 'a')) {
						max = int(s[j] - 'a');
						ind = j;
					}
				}
				else if (j != 0) {
					if (int(s[j - 1] - 'a') + 1 == int(s[j] - 'a')) {
						max = int(s[j] - 'a');
						ind = j;
					}
				}
				else if (j != s.size() - 1) {
					if (int(s[j + 1] - 'a') + 1 == int(s[j] - 'a')) {
						max = int(s[j] - 'a');
						ind = j;
					}
				}
			}
		}
		if (ind == -1)
			break;
		else
			s = s.substr(0, ind) + s.substr(ind + 1, s.size() - ind - 1);
	}
	cout << len-s.size();
	return 0;
}