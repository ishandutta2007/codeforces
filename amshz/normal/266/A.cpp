# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string a;
	cin >> n >> a;
	int ans = 0;
	for (int i=1; i<n; i++)
		if (a[i] == a[i-1]) ans++;
	cout << ans;
	return 0;
}