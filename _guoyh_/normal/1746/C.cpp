# include <bits/stdc++.h>
using namespace std;
const int MAXN = 100051;
int T, n, k;
int a[MAXN], b[MAXN], s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			b[a[i]] = i + 1;
		}
		b[a[n]] = 1;
		for (int i = 1; i <= n; i++) cout << b[i] << ' ';
		cout << '\n';
	}
	return 0;
}