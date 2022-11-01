#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int ret = 0;
	string s; cin >> s;
	int q = 0, q1 = 0;
	for(char x : s) q += (x == 'Q');
	for(char x : s)
		if(x == 'Q') q1++;
		else if(x == 'A') ret += q1 * (q - q1);
	cout << ret;
}