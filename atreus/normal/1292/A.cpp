#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

int a[2][maxn];

int get(int r, int c){
	return (a[r][c] & a[r^1][c]) + (a[r][c] & a[r^1][c-1]) + (a[r][c] & a[r^1][c+1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	int sum = 0;
	for (int i = 1; i <= q; i++){
		int r, c;
		cin >> r >> c;
		r --;
		sum -= get(r, c);
		a[r][c] ^= 1;
		sum += get(r, c);
		if (sum > 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}