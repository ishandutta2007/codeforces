# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
long long a[xn];

int main(){
	int n;
	cin >> n;
	int r = 0, t = 0;
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (a[i]%2 == 1) t += 1;
		else r += 1;
	}
	cout << min(r,t);
}