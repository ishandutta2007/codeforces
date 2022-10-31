# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
int a[xn];

int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		int ans = 1;
		sort(a, a+n);
		for (int i=1; i<n; i++)
			if (a[i] == a[i-1]+1) ans++;
		if (ans == 1) cout << 1 << endl;
		else cout << 2 << endl;
	}
}