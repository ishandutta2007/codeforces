#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	if (count(s.begin(), s.end(), '0') * 2 == n)
		cout << "2\n" << s[0] << ' ' << s.substr(1);
	else
		cout << "1\n" << s;
	return 0;
}