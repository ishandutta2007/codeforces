#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;
	for(int i = 0;; ++i)
		if(i == n - 1 || s[i] > s[i+1]) {
			s.erase(s.begin() + i);
			cout << s;
			break;
		}
	return 0;
}