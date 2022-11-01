#include <iostream>
#include <vector>
using namespace std;


bool mark[105];
vector <int> ans;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!mark[x]) {
			ans.push_back(i);
			mark[x] = true;
		}
	}
	if (ans.size() >= k) {
		cout << "YES" << endl;
		for (int i = 0; i < k; i++) {
			cout << ans[i] << " ";
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}