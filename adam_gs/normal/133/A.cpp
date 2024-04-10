#include <bits/stdc++.h>

using namespace std;

#define rep(a, b) for(int a = 0; a < (b); ++a)

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x;
	cin >> x;
	rep(i, x.size()) {
		if(x[i]=='H' || x[i]=='Q' || x[i]=='9') {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}