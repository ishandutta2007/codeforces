# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int p[xn];
int t[xn];
int h[xn];

int main(){
	int n;
	cin >> n;
	for (int i=2; i<=n; i++) cin >> p[i], h[i] = h[p[i]]+1;
	
	for (int i=1; i<=n; i++) t[h[i]]++;
	int ans = 0;
	int s = 0;
	//t[0] = 1;
	for (int i=0; i<=n; i++){
		if (t[i]%2 == 1) ans++;
	}
	cout << ans << endl;
}