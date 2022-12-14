#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 1e3 + 10;

int row[maxn], col[maxn], r[maxn], c[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int x;
			cin >> x;
			row[i] ^= x;
			col[j] ^= x;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int x;
			cin >> x;
			r[i] ^= x;
			c[j] ^= x;
		}
	}
	for (int i = 0; i < n; i++)
		if (row[i] != r[i])
			return cout << "No\n", 0;
	for (int i = 0; i < m; i++)
		if (col[i] != c[i])
			return cout << "No\n", 0;
	cout << "Yes\n";
}