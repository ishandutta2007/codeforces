#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int popCnt(int x) {
	return x ? 1 + popCnt(x&(x-1)) : 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		cout << (1 << popCnt(x)) << '\n';;
	}
	return 0;
}