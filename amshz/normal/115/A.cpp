# include <bits/stdc++.h>

using namespace std;

const int xn = 2e3+10;
int pt[xn];

int main(){
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> pt[i];
	int x = 0, mx = 0;
	for (int i=1; i<=n; i++){
		x = i;
		int t = 0;
		while (x != -1) x = pt[x], t++;
		mx = max(mx, t);
	} 
	cout << mx << endl;
}