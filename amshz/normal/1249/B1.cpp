# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn];

int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		//cout << "ans : " << endl;
		for (int i=0;i<n; i++){
			int x = a[i]-1;
			int ans = 1;
			while (x != i) x = a[x]-1, ans++;
			cout << ans << ' ';
		}
		cout << endl;
	}
}