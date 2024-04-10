#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int d[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		d[v] ++, d[u] ++;
	}
	for (int i = 1; i <= n; i++)
		if (d[i] == 2)
			return cout << "NO\n", 0;
	cout << "YES\n";
}