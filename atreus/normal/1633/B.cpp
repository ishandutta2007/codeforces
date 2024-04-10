#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '1')
				c1++;
			else
				c2++;
		cout << min(c1, c2) - (c1 == c2) << '\n';
	}
}