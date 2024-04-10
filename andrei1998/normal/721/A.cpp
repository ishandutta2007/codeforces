#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	string str;

	cin >> n;
	cin >> str;
	str = " " + str;

	vector <int> ans;
	
	for (int i = 1; i <= n; ++ i)
		if (str[i] == 'B') {
			if (i == 1 || str[i - 1] == 'W')
				ans.push_back(1);
			else
				++ ans.back();
		}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++ i)
		cout << ans[i] << " \n"[i + 1 == ans.size()];
	
	if (ans.size() == 0)
		cout << '\n';

	return 0;
}