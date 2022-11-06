#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	string s;
	cin >> s;

	string t;
	for (char c : s)
		if (t == "" || c != t.back())
			t += c;
		else
			t.pop_back();

	cout << ((s.size() - t.size()) & 2 ? "Yes" : "No");
	return 0;
}