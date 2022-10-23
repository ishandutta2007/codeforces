# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
int t, n;
int a[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int mx = 1, mi = 1;
		for (int i = 1; i <= n; i++){
			if (a[i] > a[mx]) mx = i;
			if (a[i] < a[mi]) mi = i;
		}
		cout << mi << ' ' << mx << '\n';
	}
	return 0;
}