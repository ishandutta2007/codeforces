#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	for(char x : s) {
		a += x == 'a';
		b += x == 'b';
		c += x == 'c';
	}
	s.erase(unique(all(s)), s.end());
	if(s != "abc" || a != c && b != c) cout << "NO";
	else cout << "YES";
}