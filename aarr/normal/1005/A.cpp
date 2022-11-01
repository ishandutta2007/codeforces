#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;

int a[N];
vector <int> ans;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i + 1] == 1)
			ans.push_back(a[i]);
	}
	ans.push_back(a[n - 1]);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}