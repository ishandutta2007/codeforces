# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn], b[xn], c[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i], c[b[i]] = i;
	int mn = c[a[0]];
	int ans = 0;
	for (int i=1; i<n; i++){
		if (c[a[i]] < mn) ans++;
		mn = max(mn, c[a[i]]);
	}
	cout << ans << endl;
}