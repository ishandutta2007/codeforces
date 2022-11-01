# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
long long int a[xn], b[xn], c[xn], ans[xn];

int main(){
	int n;
	long long q;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i] >> b[i] >> c[i];
	int l,r,x;
	for (int i=0; i<n; i++){
		l = 0;
		r = c[i];
		while (l < r-1){
			x = (l+r)/2;
			//cout << "i : " << i << ' ' << l << ' ' << r << endl;
			if (x+a[i] > (c[i]-x)+b[i]) r = x;
			else l = x;
		}
		if (r+a[i] > (c[i]-r)+b[i]) ans[i] = c[i]-r+1;
		if (l+a[i] > (c[i])-l+b[i]) ans[i] = c[i]-l+1;
	}
	for (int i=0; i<n; i++) cout << ans[i] << endl;
}