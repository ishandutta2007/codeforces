#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int n;
int a[222][222];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, n) rep(j, n)
		cin >> a[i][j];
	
	ll sum = 0;
	rep(i, n) rep(j, n)
		sum += a[i][j];
	
	int mn = a[0][n-1];
	rep(i, n)
		mn = min(mn, a[i][n-1-i]);
	sum -= mn;
	
	cout << sum << endl;
	
	return 0;
}