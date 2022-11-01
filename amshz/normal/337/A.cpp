# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
int a[xn];

int main(){
	int n ,m;
	cin >> m >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int mn = a[m-1]-a[0];
	for (int i=m; i<n; i++){
		if (a[i]-a[i-m+1] < mn){
			mn = a[i]-a[i-m+1];
		}
	}
	cout << mn;
	return 0;
}