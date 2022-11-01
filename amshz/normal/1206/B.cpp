# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
long long a[xn];
long long b[xn];
long long c[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	//sort(a,a+n);
	for (int i=0; i<n; i++){
		if (a[i] > 0) b[i] = a[i]+1, c[i] = a[i]-1;
		else if (a[i] == 0) b[i] = a[i]+1, c[i] = a[i]+1;
		else b[i] = -1-a[i], c[i] = 1-a[i];
	}
	long long int t = 0;
	long long int ans = 0;
	bool f = 1;
	for (int i=0; i<n; i++){
		//cout << b[i] << ' ' << c[i] << endl;
		if (b[i] < c[i]) t += 1, ans += b[i];
		else ans += c[i];
		if (b[i] == c[i]) f = 0;
	}
	if (t%2 == 1 and f) ans += 2;
	cout << ans;
}