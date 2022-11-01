#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int a = 0, n = sz(s);
	for(int i = 0; i < n; i++) a += (s[i] == '-');
	if(n - a == 0 || a % (n - a) == 0) cout << "YES";
	else cout << "NO";
}