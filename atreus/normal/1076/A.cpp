#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 1e5 + 4;

int main() {
	ios_base::sync_with_stdio (false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i + 1]) {
			for (int j = 0; j < i; j++)
				cout << s[j];
			for (int j = i + 1; j < n; j++)
				cout << s[j];
			cout << endl;
			return 0;
		}
	}
	cout << s.substr (0, n - 1) << endl;
}