#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	bool q = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if(ch == 'C' || ch == 'M' || ch == 'Y')
				q = false;
		}
	if(q) puts("#Black&White");
	else puts("#Color");
	return 0;
}