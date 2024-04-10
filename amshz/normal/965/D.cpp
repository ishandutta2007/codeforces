#include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 1e5;
int a[xn];
 
int main(){
	int n, g;
	cin >> n >> g;
	n -= 1;
	int mn = 0;
	for (int i=0; i<n; i++) cin >> a[i], mn += a[i];
	int s = 0;
	for (int i=0; i<g; i++) s += a[i];
	if (s < mn) mn = s;
	for (int i=g; i<n; i++){
		s += a[i]-a[i-g];
		if (s < mn) mn = s;
	}
	cout << mn;
}