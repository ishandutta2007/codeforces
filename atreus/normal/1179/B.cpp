#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int lo = 1, hi = n;
	while (hi > lo){
		for (int i = 1; i <= m; i++){
			cout << lo << " " << i << '\n';
			cout << hi << " " << m - i + 1 << '\n';
		}
		lo ++;
		hi --;
	}
	if (lo == hi){
		for (int i = 1; i <= m / 2; i++){
			cout << lo << " " << i << '\n';
			cout << lo << " " << m - i + 1 << '\n';
		}
		if (m & 1)
			cout << lo << " " << (m + 1) / 2 << '\n';
	}
}