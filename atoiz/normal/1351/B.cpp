#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a[2], b[2];
		cin >> a[0] >> a[1] >> b[0] >> b[1];
		bool ans = false;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (a[i] == b[j] && a[i] == a[i ^ 1] + b[j ^ 1]) {
					ans = true;
				}
			}
		}
		cout << (ans ? "Yes" : "No") << endl;
	}
}