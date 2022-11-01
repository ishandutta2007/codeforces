#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int ans = 0;
	for(char x : s) ans += (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == '1' || x == '3' || x == '5' || x == '7' || x == '9');
	cout << ans;
}