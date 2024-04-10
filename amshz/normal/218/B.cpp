# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
int a[xn];
int b[xn];

int main(){
	int n ,m;
	cin >> n >> m;
	for (int i=0; i<m; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	long long int s = 0;
	sort(a,a+m);
	sort(b,b+m);
	for (int i=0; i<n; i++){
		s += a[m-1];
		a[m-1] -= 1;
		sort(a,a+m);
	}
	long long int r = 0;
	int k = 0;
	for (int i=0; i<n; i++){
		if (b[k] > 0){
			r += b[k];
			b[k] -= 1;
		}
		else{
			k += 1;
			r += b[k];
			b[k] -= 1;
		}
	}
	cout << s << ' ' << r;
}