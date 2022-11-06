#include <bits/stdc++.h>
using namespace std;

int N;
int n, x, y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> n >> x >> y;
	cin >> s;

	
	int res = 0;
	for (int i = 1; i <= x; i++) {
		if (i - 1 == y) {
			if (s[s.length() - i] == '0') ++res;
		}
		else {
			if (s[s.length() - i] == '1') ++res;
		}
	}

	//if (s[s.length() - (x + 1)] == '0') ++res;
	cout << res << "\n";
}