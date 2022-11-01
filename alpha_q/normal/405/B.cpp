#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, i; string s; cin >> n >> s;
	int ret = 0, cnt = 0; bool L = 0;
	int start, end;
	i = 0; while (s[i] == '.' && i < n) i++;
	if (i == n) {cout << n; return 0;}
	if (s[i] == 'L') start = i + 1;
	else start = 0;
	i = n - 1; while (s[i] == '.') i--;
	if (s[i] == 'R') end = i - 1;
	else end = n - 1;
	//cout<<start<<" "<<end<<endl;
	for (i = start; i <= end; i++) {
		if (s[i] == '.') {
			if (L) cnt++;
			else ret++;
		} 
		else if (s[i] == 'R') L = 1;
		else {
			L = 0;
			if (cnt % 2) ret++;
			cnt = 0;
		}
	}
	cout << ret << endl;
	return 0;
}