# include <bits/stdc++.h>

using namespace std;

const int xn = 3e5+10;
char z[xn], f[xn];

int main(){
	int q;
	cin >> q;
	while (q--){
		string a;
		cin >> a;
		int n = a.size();
		int p1 = 0, p2 = 0;
		for (int i=0; i<n; i++){
			if (a[i] == '0' or a[i] == '4' or a[i] == '2' or a[i] == '6' or a[i] == '8') z[p1] = a[i], p1++;
			else f[p2] = a[i], p2++;
		}
		int l1 = 0, l2 = 0;
		while (l1+l2 < p1+p2){
			if (l1 == p1) cout << f[l2], l2++;
			else if (l2 == p2) cout << z[l1], l1++;
			else{
				if (z[l1] < f[l2]) cout << z[l1], l1++;
				else cout << f[l2], l2++;
			}
		}
		cout << endl;
	}
}