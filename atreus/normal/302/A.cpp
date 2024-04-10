#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x == 1)
			a ++;
		else
			b ++;
	}
	while (m --){
		int l, r;
		cin >> l >> r;
		int len = r - l + 1;
		if ((len & 1) or a < len / 2 or b < len / 2)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
}